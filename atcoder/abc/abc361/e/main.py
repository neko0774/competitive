N = int(input())
G = [[] for _ in range(N)]
ans = 0
import sys
sys.setrecursionlimit(10**7)
for _ in range(N - 1):
  A, B, C = map(int, input().split())
  A -= 1
  B -= 1
  G[A].append((B, C))
  G[B].append((A, C))
  ans += C*2

import pypyjit
pypyjit.set_param('max_unroll_recursion=-1')
def dfs(x, par):
  ret = 0
  idx = x
  for nx, c in G[x]:
    if nx == par: continue
    cost, retx = dfs(nx, x)
    cost += c
    if cost > ret:
      idx = retx
      ret = cost
  return ret, idx

p, x = dfs(0, -1)
c, _ = dfs(x, -1)
print(ans - c)