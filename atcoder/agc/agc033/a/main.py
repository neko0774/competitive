dxy = [[-1, 0], [0, -1], [1, 0], [0, 1]]
from collections import deque
def main():
    H, W = map(int, input().split())
    A = [[i for i in input()] for _ in range(H)]

    q = deque()
    cnt = 0
    ans = 0
    for x in range(W):
        for y in range(H):
            if A[y][x]=="#":
                cnt += 1
                q.append([x, y])
    
    while cnt<H*W:
        ans += 1
        nq = deque()
        while q:
            x,y = q.popleft()
            for dx, dy in dxy:
                nx, ny = x+dx, y+dy
                if 0<=nx<W and 0<=ny<H and A[ny][nx]==".":
                    nq.append([nx, ny])
                    A[ny][nx] = "#"
                    cnt += 1
        q = nq
    print(ans)
main()