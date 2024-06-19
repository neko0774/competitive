S = input()
N = len(S)

S = int(S)
mod = 998244353
inv = pow(10**N-1, mod-2, mod)
ans = S%mod*(pow(10**N, S, mod)-1)%mod
ans *= inv
ans %= mod
ans += mod
ans %= mod
print(ans)