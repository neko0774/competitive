N = int(input())
C = [[0 if i=='R' else 1 for i in input()] for _ in range(N)]

def conv(x, y):
  return y*N+x

def rev(v):
  return v%N, v//N


INF = 10**12
from collections import deque
def find(S, G, l):
  sx, sy = S[0]-1, S[1]-1
  gx, gy = G[0]-1, G[1]-1
  q = deque()
  dist = [[INF for _ in range(N)] for _ in range(N)]
  dist[sy][sx] = 0
  q.append([sx, sy, 0])
  while q:
    #print(q)
    x, y, cost = q.popleft()
    if cost>dist[y][x]: continue
    for i, j in [[0, 1], [1, 0], [-1, 0], [0, -1]]:
      nx = x+i
      ny = y+j
      if 0<=nx<N and 0<=ny<N and dist[ny][nx]>cost:
        #if l==1: print(x, y, nx, ny, cost, dist[ny][nx], C[y][x])
        if C[y][x]==1-l and dist[ny][nx]>cost+1:
          q.append([nx, ny, cost+1])
          dist[ny][nx] = cost+1
        elif dist[ny][nx]>cost and (C[y][x]==l or C[y][x]==2):
          q.appendleft([nx, ny, cost])
          dist[ny][nx] = cost
  return dist

DD = find([1, 1], [N, N], 0)
q = deque()
q.append([N-1, N-1])
cnt = DD[N-1][N-1]
seen = [[0 for _ in range(N)] for _ in range(N)]
while q:
  x, y = q.popleft()
  seen[y][x] = 1
  if DD[y][x]!=cnt:
    continue
  for i, j in [[0, 1], [1, 0], [-1, 0], [0, -1]]:
    nx = x+i
    ny = y+j
    if 0<=nx<N and 0<=ny<N and not seen[ny][nx]:
      if C[ny][nx]==1 and DD[ny][nx]==cnt-1:
        q.appendleft([nx, ny])
        C[ny][nx] = 2
        cnt -= 1
      elif DD[ny][nx]==cnt:
        q.append([nx, ny])

dd = find([1, N], [N, 1], 1)
print(DD[-1][-1]+dd[0][-1])