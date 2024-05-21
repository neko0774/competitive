#include<bits/stdc++.h>
using namespace std;

bool is_end = false;
constexpr double EPS = 1e-6;

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
  double cross = (x1 - x3) * (y2 - y3) - (y1 - y3) * (x2 - x3);
  return abs(cross) / 2.0;
}

void solve() {
  int N, P, Q, R;
  cin >> N >> P >> Q >> R;
  P--, Q--, R--;
  if(N == 0) {
    is_end = true;
    return;
  }
  vector<double> x(N), y(N);
  for(int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }
  double lensum = 0;
  vector<double> len(N), dx(N), dy(N);
  for(int i = 0; i < N; i++) {
    int j = (i + 1) % N;
    dx[i] = x[j] - x[i];
    dy[i] = y[j] - y[i];
    len[i] = hypot(dx[i], dy[i]);
    lensum += len[i];
  }
  double ans = INFINITY;
  const double cut = 10.0;
  const double dt = lensum / cut;
  tuple<double, double, int> pos_p = make_tuple(x[P], y[P], P);
  tuple<double, double, int> pos_q = make_tuple(x[Q], y[Q], Q);
  tuple<double, double, int> pos_r = make_tuple(x[R], y[R], R);
  auto mov = [&](tuple<double, double, int> &pos) {
    auto [xx, yy, i] = pos;
    int j = (i + 1) % N;
    xx += dx[i] * (dt / len[i]);
    yy += dy[i] * (dt / len[i]);
    if(abs(xx - x[j]) < EPS && abs(yy - y[j]) < EPS) i = j;
    pos = make_tuple(xx, yy, i);
  };
  for(double tim = 0; tim < lensum; tim+=dt) {
    auto [px, py, pi] = pos_p;
    auto [qx, qy, qi] = pos_q;
    auto [rx, ry, ri] = pos_r;
    cout << tim << " : " << px << " " << py << " " << qx << " " << qy << " " << rx << " " << ry << endl;
    ans = min(ans, area(px, py, qx, qy, rx, ry));
    mov(pos_p);
    mov(pos_q);
    mov(pos_r);
  }
  cout << fixed << setprecision(7) << ans << endl;
}

// void solve() {
//   int N, P, Q, R;
//   cin >> N >> P >> Q >> R;
//   P--, Q--, R--;
//   if(N == 0) {
//     is_end = true;
//     return;
//   }
//   vector<double> x(N), y(N);
//   for(int i = 0; i < N; i++) {
//     cin >> x[i] >> y[i];
//   }
//   vector<double> lsum(2 * N);
//   for(int i = 1; i < 2 * N ; i++) {
//     lsum[i] = hypot(x[i % N] - x[(i - 1) % N], y[i % N] - y[(i - 1) % N]);
//     lsum[i] += lsum[i - 1];
//   }
//   auto pos = [&](int v_begin, double t) -> pair<double, double> {
//     pair<double, double> ret;
//     int ok = v_begin, ng = 2 * N;
//     while(ok + 1 < ng) {
//       int mid = (ok + ng) / 2;
//       if(lsum[mid] - lsum[v_begin] <= t) ok = mid;
//       else ng = mid;
//     }
//     int v = ok % N;
//     int v2 = (ok + 1) % N;
//     double ra = (t - (lsum[ok] - lsum[v_begin])) / hypot(x[v] - x[v2], y[v] - y[v2]);
//     ret = make_pair(x[v] + (x[v2] - x[v]) * ra, y[v] + (y[v2] - y[v]) * ra);
//     return ret;
//   };
//   double ans = INFINITY;
//   for(int p_begin : {P, Q, R}) {
//     double len_sum = 0;
//     int p = p_begin, q, r;
//     if(p_begin == P) q = Q, r = R;
//     if(p_begin == Q) q = P, r = R;
//     if(p_begin == R) q = P, r = Q;
//     for(int i = p_begin, j = 0; j < N; i = (i + 1) % N, j++) {
//       double len = hypot(x[i] - x[(i + 1) % N], y[i] - y[(i + 1) % N]);
//       double ll = 0, rr = len;
//       while(abs(rr - ll) > EPS) {
//         double m1 = (2 * ll + rr) / 3.0;
//         double m2 = (ll + 2 * rr) / 3.0;
//         auto [px1, py1] = pos(p, len_sum + m1);
//         auto [px2, py2] = pos(p, len_sum + m2);
//         auto [qx1, qy1] = pos(q, len_sum + m1);
//         auto [qx2, qy2] = pos(q, len_sum + m2);
//         auto [rx1, ry1] = pos(r, len_sum + m1);
//         auto [rx2, ry2] = pos(r, len_sum + m2);
//         // cout << px1 << " " << py1 << " " << qx1 << " " << qy1 << " " << rx1 << " " << ry1 << endl;
//         // cout << "ans = " << ans << endl;
//         ans = min(ans, min(area(px1, py1, qx1, qy1, rx1, ry1), area(px2, py2, qx2, qy2, rx2, ry2)));
//         if(area(px1, py1, qx1, qy1, rx1, ry1) > area(px2, py2, qx2, qy2, rx2, ry2)) ll = m1;
//         else rr = m2;
//       }
//       len_sum += len;
//     }
//   }
//   cout << fixed << setprecision(7) << ans << endl;
// }

int main(){
  while(!is_end) { solve(); }
}