H, W = map(int, input().split())
S = [[i for i in input()] for _ in range(H)]
vis = [[0 for _ in range(W)] for _ in range(H)]
cnt = [0] * (H * W)
id = [[0 for _ in range(W)] for _ in range(H)]
dxy = [[0, 1], [1, 0], [-1, 0], [0, -1]]
num = 0
start = -1
sx = -1
sy = -1
from collections import deque
for y in range(H):
  for x in range(W):
    if vis[y][x] or S[y][x] == '#': continue
    num += 1
    vis[y][x] = 1
    q = deque()
    q.append([x, y])

    while q:
      cx, cy = q.popleft()
      id[cy][cx] = num
      cnt[num] += 1

      if S[cy][cx] == 'S':
        sx = cx
        sy = cy
        start = num

      for di, dj in dxy:
        nx = cx + di
        ny = cy + dj
        if 0 <= nx < W and 0 <= ny < H and S[ny][nx] != '#' and not vis[ny][nx]:
          q.append([nx, ny])
          vis[ny][nx] = 1
ans = 0

assert sx != -1
assert sy != -1
assert start != -1

ans = 0
for x in range(W):
  for y in range(H):
    if id[y][x] != id[sy][sx]: continue

    for di, dj in dxy:
      nx = x + di
      ny = y + dj
      
      if 0 <= nx < W and 0 <= ny < H and S[ny][nx] == '#':
        ans = max(ans, 1)

        for ddi, ddj in dxy:
          nnx, nny = nx + ddi, ny + ddj

          if 0 <= nnx < W and 0 <= nny < H and id[nny][nnx] != id[ny][nx] and S[nny][nnx] != '#':
            assert id[ny][nx] == id[sy][sx]
            ans = max(ans, cnt[id[nny][nnx]] + 1)

#print(cnt)
#print(id)
print(ans + cnt[id[sy][sx]])