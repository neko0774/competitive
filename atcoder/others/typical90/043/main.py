H, W = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())
dxy = [[1, 0, 0], [-1, 0, 1], [0, 1, 2], [0, -1, 3]]
sx -= 1
sy -= 1
gx -= 1
gy -= 1
INF = 10**12

#0 -> right
#1 -> left
#2 -> up
#3 -> down
S = [[i for i in input()] for _ in range(H)]
from collections import deque
q = deque([[sx, sy, i] for i in range(4)])
dist = [[[INF]*4 for _ in range(W)] for _ in range(H)]
for i in range(4):
    dist[sy][sx][i] = 0
while q:
    print(q)
    x, y, d = q.popleft()
    for i, j, nd in dxy:
        nx = x+i
        ny = y+j
        if 0<=nx<W and 0<=ny<H and dist[ny][nx][nd]==INF and S[ny][nx]==".":
            if d==nd:
                dist[ny][nx][d] = dist[y][x][d]
                q.appendleft([nx, ny, d])
            else:
                dist[ny][nx][nd] = dist[y][x][d]+1
                q.append([nx, ny, nd])
print(dist)
print(min(dist[gy][gx]))