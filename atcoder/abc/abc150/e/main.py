N = int(input())
C = [int(i) for i in input().split()]
mod = 10**9+7
rev = pow(2, mod-2, mod)
C.sort()
ans = 0
for i in range(N):
  ans += C[i]*(1+(N-i))*rev%mod*pow(2, 2*N-1, mod)
  ans %= mod
print(ans)