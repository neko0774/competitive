mod =  998244353
def main():
    N, M, K = map(int, input().split())
    inv = pow(M, mod-2, mod)
    dp = [[0 for _ in range(N+1)] for _ in range(K+1)]
    dp[0][0] = 1

    for k in range(K):
        for n in range(N):
            for m in range(1, M+1):
                if n+m<=N:
                    dp[k+1][n+m] += dp[k][n]*inv
                    dp[k+1][n+m] %= mod
                else:
                    dp[k+1][2*N-n-m] += dp[k][n]*inv
                    dp[k+1][2*N-n-m] %= mod
        dp[k+1][N] += dp[k][N]
        dp[k+1][N] %= mod
    print(dp[K][N]%mod)


main()