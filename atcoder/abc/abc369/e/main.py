N, M = map(int, input().split())
bridge = []
INF = 10**15
dist = [[INF for _ in range(N)] for _ in range(N)]
for _ in range(M):
  u, v, t = map(int, input().split())
  u -= 1
  v -= 1
  bridge.append((u, v, t))
  dist[u][v] = min(t, dist[u][v])
  dist[v][u] = min(t, dist[u][v])

for i in range(N):
  dist[i][i] = 0

for k in range(N):
  for i in range(N):
    for j in range(N):
      dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j])

import itertools as it
Q = int(input())
for _ in range(Q):
  K = int(input())
  B = [int(i) - 1 for i in input().split()]
  res = INF
  for iter in it.permutations(B):
    ans = [bridge[iter[0]][2], bridge[iter[0]][2]]
    u = bridge[iter[0]][0]
    v = bridge[iter[0]][1]
    ans[0] += dist[0][u]
    ans[1] += dist[0][v]
    for b in iter[1:]:
      nans = [INF, INF]
      nu = bridge[b][0]
      nv = bridge[b][1]
      nans[0] = min(ans[0] + dist[v][nu], ans[1] + dist[u][nu]) + bridge[b][2]
      nans[1] = min(ans[0] + dist[v][nv], ans[1] + dist[u][nv]) + bridge[b][2]
      u = nu
      v = nv
      ans = nans
    #print(iter, ans, u, v, N - 1, dist[v][N - 1], dist[u][N - 1])
    res = min(ans[0] + dist[v][N - 1], ans[1] + dist[u][N - 1], res)
  print(res)