def main():
    N, K, D = map(int, input().split())
    A = [int(i) for i in input().split()]


    dp = [[[-1 for _ in range(D)] for _ in range(K+1)] for _ in range(N+1)]
    dp[0][0][0] = 0
    for n in range(1, N+1):
        num = A[n-1]
        dp[n][0][0] = 0
        for k in range(1, K+1):
            for d in range(D):
                if (dp[n-1][k-1][(d-num)%D]+num)%D == d and not dp[n-1][k-1][(d-num)%D]==-1:
                    dp[n][k][d] = max(dp[n-1][k][d], dp[n-1][k-1][(d-num)%D]+num)
                else:
                    dp[n][k][d] = dp[n-1][k][d]
    print(dp[-1][-1][0])  

main()