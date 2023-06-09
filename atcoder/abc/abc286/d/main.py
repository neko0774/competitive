def main():
    N, X = map(int, input().split())
    coin = []
    dp = [[0]*(X+1) for _ in range(N+1)]
    dp[0][0] = 1
    for i in range(1, N+1):
        A, B = map(int, input().split())

        for _ in range(B):
            for x in range(X+1)[::-1]:
                c = []
                if x-A>=0:
                    dp[i][x] = max(dp[i-1][x], dp[i][x], dp[i][x-A], dp[i-1][x-A])
                else:
                    dp[i][x] = max(dp[i-1][x], dp[i][x])
    print("Yes" if dp[-1][-1] else "No") 

main()