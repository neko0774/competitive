import sys
input = sys.stdin.readline
H, W = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())
dxy = [[1, 0, 0], [-1, 0, 1], [0, 1, 2], [0, -1, 3]]
sx -= 1
sy -= 1
gx -= 1
gy -= 1
INF = 10**9

#0 -> right
#1 -> left
#2 -> up
#3 -> down
def change(x, y):
    return y*W+x
S = [[i for i in input()] for _ in range(H)]
from collections import deque
q = deque([[sx, sy, i] for i in range(4)])
dist = [[INF]*4 for _ in range(W*H)]
for i in range(4):
    dist[change(sx, sy)][i] = 0
while q:
    print(q)
    x, y, d = q.popleft()
    if x==gx and y==gy:
        print(dist[change(gx, gy)][d])
        exit()
    for i, j, nd in dxy:
        nx = x+i
        ny = y+j
        if 0<=nx<W and 0<=ny<H and S[ny][nx]==".":
            if d==nd and dist[change(nx, ny)][d]>dist[change(x, y)][d]:
                dist[change(nx, ny)][d] = dist[change(x, y)][d]
                q.appendleft([nx, ny, d])
            elif dist[change(nx, ny)][nd]>dist[change(nx, ny)][d]+1:
                dist[change(nx, ny)][nd] = dist[change(x, y)][d]+1
                q.append([nx, ny, nd])
print(dist)