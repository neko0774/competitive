#include <bits/stdc++.h>
using namespace std;
#define ll long long

namespace internal {
using i64 = long long;
using u64 = unsigned long long;
using u128 = __uint128_t;

template <int BASE_NUM = 2>
struct Hash : array<u64, BASE_NUM> {
  using array<u64, BASE_NUM>::operator[];
  static constexpr int n = BASE_NUM;

  Hash() : array<u64, BASE_NUM>() {}

  static constexpr u64 md = (1ull << 61) - 1;

  constexpr static Hash set(const i64 &a) {
    Hash res;
    fill(begin(res), end(res), cast(a));
    return res;
  }
  Hash &operator+=(const Hash &r) {
    for (int i = 0; i < n; i++)
      if (((*this)[i] += r[i]) >= md) (*this)[i] -= md;
    return *this;
  }
  Hash &operator+=(const i64 &r) {
    u64 s = cast(r);
    for (int i = 0; i < n; i++)
      if (((*this)[i] += s) >= md) (*this)[i] -= md;
    return *this;
  }
  Hash &operator-=(const Hash &r) {
    for (int i = 0; i < n; i++)
      if (((*this)[i] += md - r[i]) >= md) (*this)[i] -= md;
    return *this;
  }
  Hash &operator-=(const i64 &r) {
    u64 s = cast(r);
    for (int i = 0; i < n; i++)
      if (((*this)[i] += md - s) >= md) (*this)[i] -= md;
    return *this;
  }
  Hash &operator*=(const Hash &r) {
    for (int i = 0; i < n; i++) (*this)[i] = modmul((*this)[i], r[i]);
    return *this;
  }
  Hash &operator*=(const i64 &r) {
    u64 s = cast(r);
    for (int i = 0; i < n; i++) (*this)[i] = modmul((*this)[i], s);
    return *this;
  }

  Hash operator+(const Hash &r) { return Hash(*this) += r; }
  Hash operator+(const i64 &r) { return Hash(*this) += r; }
  Hash operator-(const Hash &r) { return Hash(*this) -= r; }
  Hash operator-(const i64 &r) { return Hash(*this) -= r; }
  Hash operator*(const Hash &r) { return Hash(*this) *= r; }
  Hash operator*(const i64 &r) { return Hash(*this) *= r; }
  Hash operator-() const {
    Hash res;
    for (int i = 0; i < n; i++) res[i] = (*this)[i] == 0 ? 0 : md - (*this)[i];
    return res;
  }
  friend Hash pfma(const Hash &a, const Hash &b, const Hash &c) {
    Hash res;
    for (int i = 0; i < n; i++) res[i] = modfma(a[i], b[i], c[i]);
    return res;
  }
  friend Hash pfma(const Hash &a, const Hash &b, const i64 &c) {
    Hash res;
    u64 s = cast(c);
    for (int i = 0; i < n; i++) res[i] = modfma(a[i], b[i], s);
    return res;
  }

  Hash pow(long long e) {
    Hash a{*this}, res{Hash::set(1)};
    for (; e; a *= a, e >>= 1) {
      if (e & 1) res *= a;
    }
    return res;
  }

  static Hash get_basis() {
    static auto rand_time =
        chrono::duration_cast<chrono::nanoseconds>(
            chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    static mt19937_64 rng(rand_time);
    Hash h;
    for (int i = 0; i < n; i++) {
      while (isPrimitive(h[i] = rng() % (md - 1) + 1) == false)
        ;
    }
    return h;
  }

 private:
  static u64 modpow(u64 a, u64 b) {
    u64 r = 1;
    for (a %= md; b; a = modmul(a, a), b >>= 1) r = modmul(r, a);
    return r;
  }
  static bool isPrimitive(u64 x) {
    for (auto &d : vector<u64>{2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321})
      if (modpow(x, (md - 1) / d) <= 1) return false;
    return true;
  }
  static inline constexpr u64 cast(const long long &a) {
    return a < 0 ? a + md : a;
  }
  static inline constexpr u64 modmul(const u64 &a, const u64 &b) { 
    u128 d = u128(a) * b;
    u64 ret = (u64(d) & md) + u64(d >> 61);
    return ret >= md ? ret - md : ret;
  }
  static inline constexpr u64 modfma(const u64 &a, const u64 &b, const u64 &c) {
    u128 d = u128(a) * b + c;
    u64 ret = (d >> 61) + (u64(d) & md);
    return ret >= md ? ret - md : ret;
  }
};

}  // namespace internal

/**
 * @brief ハッシュ構造体
 * @docs docs/internal/internal-hash.md
 */

#include<atcoder/segtree>

namespace RollingHashonSegmentTreeImpl {

constexpr int BASE_NUM = 1;
using Hash = internal::Hash<BASE_NUM>;
using T = pair<Hash, int>;

vector<Hash> Pow{Hash::set(1)};
const Hash Basis = Hash::get_basis();
const Hash Zero = Hash::set(0);

T op(T a, T b) {
  while (b.second >= (int)Pow.size()) {
    Hash h = Pow.back();
    Pow.push_back(h * Basis);
  }
  Hash h = pfma(a.first, Pow[b.second], b.first);
  int len = a.second + b.second;
  return make_pair(h, len);
}
T e() { return make_pair(Zero, 0); }

template <typename Str>
struct RollingHashonSegmentTree {
  using Value = typename Str::value_type;
  int n;
  atcoder::segtree<T, op, e> seg;

  RollingHashonSegmentTree() : n(0) {}

  RollingHashonSegmentTree(const Str& S) : n(S.size()) {
    vector<T> init(n);
    for (int i = 0; i < n; i++) {
      init[i] = make_pair(Hash::set(S[i]), 1);
    }
    seg = {init};
  }

  void update(int i, const Value& v) {
    assert(0 <= i and i < n);
    seg.set(i, make_pair(Hash::set(v), 1));
  }

  // [l1, r1) と [l2, r2) が一致するかを判定
  bool same(int l1, int r1, int l2, int r2) {
    assert(0 <= l1 and l1 <= r1 and r1 <= n);
    assert(0 <= l2 and l2 <= r2 and r2 <= n);
    if (r1 - l1 != r2 - l2) return false;
    return seg.prod(l1, r1) == seg.prod(l2, r2);
  }
};
}  // namespace RollingHashonSegmentTreeImpl

using RollingHashonSegmentTreeImpl::RollingHashonSegmentTree;

int main(){
  int N, Q;
  cin >> N >> Q;
  RollingHashonSegmentTree A(N), B(N);
}