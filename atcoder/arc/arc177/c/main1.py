N = int(input())
C = [[0 if i=='R' else 1 for i in input()] for _ in range(N)]
from collections import deque
INF = 10**12
def find(S, G, l):
  sx, sy = S[0]-1, S[1]-1
  gx, gy = G[0]-1, G[1]-1
  q = deque()
  dist = [[INF for _ in range(N)] for _ in range(N)]
  dist[sy][sx] = 0
  q.append([sx, sy, 0])
  while q:
    x, y, cost = q.popleft()
    for i, j in [[0, 1], [1, 0], [-1, 0], [0, -1]]:
      nx = x+i
      ny = y+j
      if 0<=nx<N and 0<=ny<N and dist[ny][nx]==INF:
        if C[ny][nx]==1-l:
          q.append([nx, ny, cost+1])
          dist[ny][nx] = cost+1
        else:
          q.appendleft([nx, ny, cost])
          dist[ny][nx] = cost
  return dist

q = deque()
q.append([N-1, N-1])
seen = [[0 for _ in range(N)] for _ in range(N)]
D1 = find([1, 1], [N, N], 0)
cnt = D1[-1][-1]
while q:
  x, y = q.popleft()
  for i, j in [[0, 1], [1, 0], [-1, 0], [0, -1]]:
    nx = x+i
    ny = y+j
    if 0<=nx<N and 0<=ny<N and not seen[ny][nx]:
      if D1[ny][nx]==D1[y][x]==cnt and C[ny][nx]==1 and C[y][x]==0:
        q.append([nx, ny])
        C[ny][nx] = 2
        seen[ny][nx] = 1
        cnt-=1
      else:
        q.append([nx, ny])
        seen[ny][nx] = 1

D2 = find([1, N], [N, 1], 1)

print(D1[-1][-1]+D2[0][-1])