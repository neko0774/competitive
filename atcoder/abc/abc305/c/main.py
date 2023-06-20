H, W = map(int, input().split())
S = [[i for i in input()] for _ in range(H)]
dxy = [[1, 0], [-1, 0], [0, 1], [0, -1]]

def judge(x, y):
    cnt = 0
    for i, j in dxy:
        nx = x+i
        ny = y+j
        if 0<=nx<W and 0<=ny<H and S[ny][nx]=="#":
            cnt += 1
    if cnt>=2:
        return True
    return False
    


for x in range(W):
    for y in range(H):
        if S[y][x]=="." and judge(x, y):
            print(y+1, x+1)
            exit()
