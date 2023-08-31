N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
  A, B, C = map(int, input().split())
  A-=1
  B-=1
  G[A].append((B, C))
  G[B].append((A, C))

import sys
sys.setrecursionlimit(10**6)
ans = 0
seen = [0]*N
def dfs(x, dist):
  global ans
  seen[x] = 1
  for nx, d in G[x]:
    if not seen[nx]:
      seen[nx] = 1
      dfs(nx, dist+d)
      seen[nx] = 0
  ans = max(ans, dist)
  seen[x] = 0

for i in range(N):
  dfs(i, 0)
print(ans)