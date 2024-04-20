S = [int(i) for i in input()][::-1]
N = len(S)
dp = [[0, 11] for _ in range(N+1)]

for n, s in enumerate(S):
  dp[n+1][0] = min(dp[n][0]+s, dp[n][1]+s)
  dp[n+1][1] = min(dp[n][0]+11-s, dp[n][1]+9-s)
print(min(dp[-1][0], dp[-1][1]))
