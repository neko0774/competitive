T = input()
N = int(input())
A = []
S = []
for _ in range(N):
  V = [i for i in input().split()]
  A.append(V[0])
  S.append(V[1:])

INF = 10**12
dp = [[INF for _ in range(len(T)+1)] for _ in range(N+1)]

dp[0][0] = 0
for  i in range(N):
  for t in range(len(T)+1):
    if dp[i][t]==INF: continue
    for s in S[i]:
      if len(T)>=len(s)+t and T[t:len(s)+t]==s:
        dp[i+1][t+len(s)] = min(dp[i][t]+1, dp[i+1][t+len(s)])
    dp[i+1][t] = min(dp[i+1][t], dp[i][t])
print(-1 if dp[-1][-1] ==INF else dp[-1][-1])