N, M = map(int, input().split())
S = [int(i) for i in input()][::-1]

inf = 10**12
dp = [inf for _ in range(N+1)]
dp[0] = 0
cur = 0
while cur<N:
  nxt = -1
  for nx in range(cur+1, cur+M+1):
    if nx>N: break
    if S[nx] == 0:
      dp[nx] = dp[cur]+1
      nxt = nx
  if nxt==-1:break
  cur = nxt

cur = 0
ans = []
if dp[-1]==inf:
  print(-1)
  exit()
dp = dp[::-1]
for i in range(1, N+1):
  if dp[i]!=inf and dp[cur]!=dp[i]:
    ans.append(i-cur)
    cur = i
print(*ans)