H, W = map(int, input().split())
S = [[i for i in input()] for _ in range(H)]
dxy = [[0, -1], [-1, 0], [1, 0], [0, 1]]
from collections import deque
def solve(x, y):
    q = deque([[x, y]])
    dist = [[-1]*W for _ in range(H)]
    dist[y][x] = 0
    while q:
        x, y = q.popleft()
        for dx, dy in dxy:
            nx, ny = x+dx, y+dy
            if 0<=nx<W and 0<=ny<H and S[ny][nx]=="." and dist[ny][nx]==-1:
                q.append([nx, ny])
                dist[ny][nx] = dist[y][x]+1
    return max(max(i) for i in dist)
ans = 0
for x in range(W):
    for y in range(H):
        if S[y][x]=="#": continue
        ans = max(ans, solve(x, y))
print(ans)