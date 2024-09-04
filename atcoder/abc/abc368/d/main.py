import sys
sys.setrecursionlimit(10 ** 6)
N, K = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(N - 1):
  u, v = map(int, input().split())
  u -= 1
  v -= 1
  G[u].append(v)
  G[v].append(u)

V = [int(i) - 1 for i in input().split()]
is_included = set(V)

import pypyjit
pypyjit.set_param('max_unroll_recursion=-1')
def dfs(x, pre):
  cnt = 0
  for nx in G[x]:
    if nx == pre: continue
    cnt += dfs(nx, x) 
  if x in is_included or cnt > 0:
    cnt += 1
  return cnt

print(dfs(V[0], -1))