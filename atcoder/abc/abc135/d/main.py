mod = 10**9+7
def main():
    S = input()
    N = len(S)
    dp = [[0]*13 for _ in range(N+1)]
    dp[0][0] = 1
    r = 1
    for n,s in enumerate(S[::-1]):
        if s == "?":
            for k in range(10):
                for j in range(13):
                    dp[n+1][(r*k+j)%13] += dp[n][j]
                    dp[n+1][(r*k+j)%13] %= mod
        else:
            s = int(s)
            for j in range(13):
                dp[n+1][(s*r+j)%13] += dp[n][j]
                dp[n+1][(s*r+j)%13] %= mod
        r *= 10
        r %= 13
    print(dp[-1][5])



main()