HA, WA = map(int, input().split())
A = [[1 if i=="#" else 0 for i in input()] for _ in range(HA)]
HB, WB = map(int, input().split())
B = [[1 if i=="#" else 0 for i in input()] for _ in range(HB)]
HX, WX = map(int, input().split())
X = [[1 if i=="#" else 0 for i in input()] for _ in range(HX)]


def is_same(A, B):
    for x in range(WX):
        for y in range(HX):
            if A[y][x]!=B[y][x]: return 0
    return 1


for ax in range(-11, 11):
    for ay in range(-11, 11):
        for bx in range(-11, 11):
            for by in range(-11, 11):
                ans = [[0 for _ in range(WX)] for _ in range(HX)]
                is_end = 0
                for x in range(WA):
                    for y in range(HA):
                        nx = x+ax
                        ny = y+ay
                        if 0<=nx<WX and 0<=ny<HX and A[y][x]==1:
                            ans[ny][nx] = 1
                        elif A[y][x]==1: is_end = 1

                for x in range(WB):
                    for y in range(HB):
                        nx = x+bx
                        ny = y+by
                        if 0<=nx<WX and 0<=ny<HX and B[y][x]==1:
                            ans[ny][nx] = 1
                        elif B[y][x]==1: is_end = 1
                if is_end: continue
                if is_same(ans, X):
                    print("Yes")
                    exit()
print("No")
