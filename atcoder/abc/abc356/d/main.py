N, M = map(int, input().split())
ans = 0
mod = 998244353
for i in range(60):
  if (1<<i)&M:
    ans += N//(1<<(i+1))*(1<<i) + max(0, N%(1<<(i+1)) - (1<<i) + 1)%mod
    ans %= mod
print(ans)