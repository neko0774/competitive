N = int(input())
A = [int(i) for i in input().split()]
mod = 10**9 + 7

upper = max(A) * N
lower = min(A) * N
print(upper, lower)
dp = [[0 for _ in range(abs(upper) + abs(lower) + 1)] for _ in range(N)]
dp[0][0] = 1
for i in range(N):
  for v in range(lower, upper):
    if dp[i][v] == 0: continue
    for j in range(i+1, N):
      if v == A[j]: continue
      dp[j][min(v + A[j], upper + 1)] += dp[i][v]
      dp[j][min(v + A[j], upper + 1)] %= mod

for i in range(N):
  print(dp[i])
print(sum(dp[-1])%mod)