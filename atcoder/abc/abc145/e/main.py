N, T = map(int, input().split())
foods = [[int(i) for i in input().split()] for _ in range(N)]
dp = [0]*T
ans = 0
for i in range(N):
    ndp = dp[:]
    ans = max(ans, dp[-1]+foods[i][1])
    for t in range(T):
        if t-foods[i][0]>=0:ndp[t] = max(ndp[t], dp[t-foods[i][0]]+foods[i][1])
    dp = ndp
print(ans)