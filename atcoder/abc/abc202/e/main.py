import sys
sys.setrecursionlimit(10**9+7)
N = int(input())
P = [int(i)-1 for i in input().split()]
G = [[] for _ in range(N)]
depth = [[] for _ in range(N)]
t = 0
time = 0
IN = [-1]*N
OUT = [-1]*N
for n, p in enumerate(P):
  G[p].append(n+1)
def dfs(x):
  global time, t
  IN[x] = time
  depth[t].append(time)
  time += 1
  t += 1
  for nx in G[x]:
    dfs(nx)
  t -= 1
  OUT[x] = time
  time += 1

from bisect import bisect_left as bl
Q = int(input())
dfs(0)
for _ in range(Q):
  u,d = map(int, input().split())
  #d -= 1
  u -= 1
  l = bl(depth[d], IN[u])
  r = bl(depth[d], OUT[u])
  print(r-l)
