H, W = map(int, input().split())
A = [[i for i in input()] for _ in range(H)]
N = int(input())
med = dict()
pos = dict()
places = []
for i in range(N):
  r, c, e = map(int, input().split())
  med[(r-1, c-1)] = e
  pos[(r-1, c-1)] = i
  places.append([r-1, c-1])

for y in range(H):
  for x in range(W):
    if A[y][x] == 'S' and (y, x) not in pos:
      print("No")
      exit()
    if A[y][x] == 'T':
      pos[(y, x)] = N
      med[(y, x)] = 0

inf = 10**12
dxy = [[0, 1], [1, 0], [0, -1], [-1, 0]]
from collections import deque
gG = []
def bfs(y, x):
  q = deque()
  q.append([x, y, 0])
  dist = [inf for _ in range(N+1)]
  seen = [[0 for _ in range(W)] for _ in range(H)]
  seen[y][x] = 1
  while q:
    cx, cy, c = q.popleft()
    if (cy, cx) in pos and c<=med[(y, x)]:
      dist[pos[(cy, cx)]] = 1
    for i, j in dxy:
      nx, ny = cx+i, cy+j
      if 0<=nx<W and 0<=ny<H and A[ny][nx]!='#' and not seen[ny][nx]:
        seen[ny][nx] = 1
        q.append([nx, ny, c+1])
  return dist

for x, y in places:
  gG.append(bfs(x, y))
gG.append([inf for _ in range(N+1)])
#print(gG)

to_visit = deque()
visited = set()
visited.add(0)
to_visit.append(0)
while to_visit:
  x = to_visit.popleft()
  for i in range(N+1):
    nx = gG[x][i]
    if nx!=inf and not i in visited:
      to_visit.append(i)
      visited.add(i)

print("Yes" if N in visited else "No")