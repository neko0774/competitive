N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
  A, B = map(int, input().split())
  A-=1
  B-=1
  G[B].append(A)

def dfs(x):
  if seen[x]: 
  for nx in G[x]:
    dfs(nx)