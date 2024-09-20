H, W = map(int, input().split())
S = [[i for i in input()] for _ in range(H)]
from collections import deque
dxy = [[0, 1], [1, 0], [-1, 0], [0, -1]]
def solve(grid):
  q = deque()
  ret = 0
  q.append([sx, sy])
  vis = [[0 for _ in range(W)] for _ in range(H)]
  while q:
    x, y = q.popleft()
    vis[y][x] = 1
    ret += 1
    for di, dj in dxy:
      nx = di + x
      ny = y + dj
      if 0 <= nx < W and 0 <= ny < H and S[ny][nx] == '.' and not vis[ny][nx]:
        q.append([nx, ny])
  return ret

for x in range(W):
  for y in range(H):
    if S[y][x] == 'S':
      sx = x
      sy = y

ans = solve(S)
for x in range(W):
  for y in range(H):
    if S[y][x] == '#':
      S[y][x] = '.'
      ans = max(ans, solve(S))
      S[y][x] = '#'
print(ans)