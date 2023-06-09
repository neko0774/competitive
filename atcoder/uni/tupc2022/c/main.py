H, W, N = map(int, input().split())
black = set()
check = set()
dxy = [[0, 1], [1, 0], [1, 1]]
for _ in range(N):
    x, y = map(int, input().split())
    black.add((x, y))
    for i, j in dxy:
        check.add((x+i, y+j))
ans = 0
for x, y in check:
    cnt = 0
    for i, j in dxy:
        nx, ny = x+i, y+j
        if (nx, ny) in black: cnt += 1
    ans += 1-cnt%2
print(ans)