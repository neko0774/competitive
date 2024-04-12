N = int(input())
S = [i for i in input()]
mod = 998244353

dp = [[[0 for _ in range(10)] for _ in range(1<<10)] for _ in range(N+1)]
for i in range(N):
  v = ord(S[i])-ord('A')
  dp[i+1][1<<v][v] += 1
  for j in range(1<<10):
    for k in range(10):
      #not visited or last visited
      if v==k or not 1<<v&j:
        dp[i+1][1<<v|j][v] += dp[i][j][k]
        dp[i+1][1<<v|j][v] %= mod
      dp[i+1][j][k] += dp[i][j][k]
      dp[i+1][j][k] %= mod
#print(dp[-1])
ans = 0
for ary in dp[-1]:
  ans += sum(ary)
  ans %= mod

print(ans)