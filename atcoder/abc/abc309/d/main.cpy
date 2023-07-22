from collections import deque
N1, N2, M = map(int, input().split())
G1 = [[] for _ in range(N1)]
G2 = [[] for _ in range(N2)]
for _ in range(M):
  u, v = map(int, input().split())
  u -= 1
  v -= 1
  if 0<=u<=N1:
    G1[u].append(v)
    G1[v].append(u)
  else:
    u -= N1
    v -= N1
    G2[u].append(v)
    G2[v].append(u)

def find_dist(s, G, N):
  dist = [-1]*N
  q = deque([s])
  dist[s] = 0
  while q:
    x = q.popleft()
    for nx in G[x]:
      if dist[nx]==-1:
        dist[nx] = dist[x]+1
        q.append(nx)
  return max(dist)
ans = find_dist(0, G1, N1)+find_dist(N2-1, G2, N2)
print(ans)