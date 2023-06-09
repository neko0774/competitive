def main():
    H, W = map(int, input().split())
    C = [[int(i) for i in input().split()] for _ in range(10)]
    A = [[int(i) for i in input().split()] for _ in range(H)]


    for k in range(10):
        for j in range(10):
            for i in range(10):
                C[i][j] = min(C[i][j], C[i][k]+C[k][j])
    ans = 0
    for y in range(H):
        for x in range(W):
            if A[y][x]>=0: ans += C[A[y][x]][1]
    print(ans)
main()