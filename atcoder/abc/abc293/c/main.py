H, W = map(int, input().split())
A = [[int(i) for i in input().split()] for _ in range(H)]
import sys
sys.setrecursionlimit(10**6)

ans = 0
dxy = [[0, 1], [1, 0]]
import pypyjit
pypyjit.set_param('max_unroll_recursion=-1')
def dfs(x, y, seen):
    global ans
    if x==W-1 and y==H-1:
        ans += 1
        return
    for i, j in dxy:
        nx, ny = x+i, y+j
        if 0<=nx<W and 0<=ny<H and A[ny][nx] not in seen:
            seen.add(A[ny][nx])
            dfs(nx, ny, seen)
            seen.discard(A[ny][nx])
dfs(0, 0, set([A[0][0]])) 
print(ans)
