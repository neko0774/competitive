from collections import deque
dxy = [[0, 1], [1, 0], [-1, 0], [0, -1]]

while True:
    W, H = map(int, input().split())
    S = [[i for i in input()] for _ in range(H)]
    if W==H==0: exit()
    seen = [[0]*W for _ in range(H)]
    ansB = 0
    ansW = 0
    for x in range(W):
        for y in range(H):
            if seen[y][x]==0 and S[y][x]==".":
                #print(x, y)
                q = deque([[x, y]])
                seen[y][x] = 1
                black = 0
                white = 0
                cnt = 1
                while q:
                    x, y = q.popleft()
                    for i, j in dxy:
                        nx = x+i
                        ny = y+j
                        if 0<=nx<W and 0<=ny<H:
                            if S[ny][nx]=="B":
                                black = 1
                            elif S[ny][nx]=="W":
                                white = 1
                            elif seen[ny][nx]==0:
                                seen[ny][nx] = 1
                                q.append([nx, ny])
                                cnt += 1
                if black==white==1:
                    continue
                elif black==1:
                    ansB += cnt
                elif white==1:
                    ansW += cnt
                #print(ansB, cnt, x, y, black, white)
    print(ansB, ansW)