N, A = map(int, input().split())
X = [int(i) for i in input().split()]

dp = [[0]*(50*50+1) for _ in range(N+1)]
dp[0][0] = 1
for x in X:
    ndp = [[0]*(50*50+1) for _ in range(N+1)]
    for j in range(N+1):
        for n in range(50*50+1):
            ndp[j][n] += dp[j][n]
            if j+1<N+1 and n+x<50*50+1: ndp[j+1][n+x] += dp[j][n]
    dp = ndp
ans = 0
for j in range(1, N+1):
    for n in range(50*50+1):
        if n/j==A: ans += dp[j][n]
print(ans)