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
S=[1 if x=="." else 0 for _ in range(H) for x in input().rstrip()]

from collections import deque
q = deque([[sx, sy, i] for i in range(4)])
dist = [INF for _ in range(W*H*4)]
def ch(x, y, d):
    return 4*(y*W+x)+d
for i in range(4):
    dist[ch(sx, sy, i)] = 0
while q:
    x, y, d = q.popleft()
    m = dist[ch(x, y, d)]
    if x==gx and y==gy:
        print(m)
        exit()
    nx = x+dxy[d][0]
    ny = y+dxy[d][1]
    if 0<=nx and nx<W and ny<H and 0<=ny and S[ny*W+nx] and dist[ch(nx, ny, d)]>m:
        dist[ch(nx, ny, d)] = m
        q.appendleft([nx, ny, d])
    
    for i, j, nd in dxy:
        nx = x+i
        ny = y+j
        #print(nx, ny, S[ny][nx], dist[change(nx, ny)])
        if d!=nd and 0<=nx and nx<W and 0<=ny and ny<H and S[ny*W+nx] and dist[ch(nx, ny, nd)]>m+1:
                dist[ch(nx, ny, nd)] = m+1
                q.append([nx, ny, nd])