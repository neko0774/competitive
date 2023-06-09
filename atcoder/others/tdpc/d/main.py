def main():
    N, D = map(int, input().split())
    n2, n3, n5 = 0,0,0
    while D%2==0:
        D //= 2
        n2 += 1
    while D%3==0:
        D //= 3
        n3 += 1
    while D%5==0:
        D //= 5
        n5 += 1
    ans = 0
    if D>1:
        print(0)
        return
    dp = [[[0]*(n2+1) for _ in range(n3+1)] for _ in range(n5+1)]
    dp[0][0][0] = 1
    for n in range(N):
        ndp = [[[0]*(n2+1) for _ in range(n3+1)] for _ in range(n5+1)] 
        for i in range(n2+1):
            for j in range(n3+1):
                for k in range(n5+1):
                    ndp[min(k+1, n5)][j][i] += dp[k][j][i]
                    ndp[k][min(j+1, n3)][i] += dp[k][j][i]
                    ndp[k][j][min(i+1, n2)] += dp[k][j][i]
                    ndp[k][j][min(i+2, n2)] += dp[k][j][i]
                    ndp[k][min(j+1, n3)][min(i+1, n2)] += dp[k][j][i]
                    ndp[k][j][i] += dp[k][j][i]
        dp = ndp
    print(dp[-1][-1][-1]/(6**N))
main()