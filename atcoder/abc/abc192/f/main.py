N, X = map(int, input().split())
A = [int(i) for i in input().split()]
ans = 10**18
#O(N^4)
#at ith with j numbers are used when k is left, the maximum number
for n in range(1, N+1):
    #using n potions
    #at ith potion, using j potions so far and, sum%n = k, the maximum basic points 
    dp = [[[-1]*n for _ in range(n+1)] for _ in range(N+1)]
    for i in range(N):
        dp[i][0][0] = 0
        for j in range(n+1):
            for k in range(n):
                if j-1>=0 and dp[i][j-1][(k-A[i])%n]!=-1: dp[i+1][j][k] = max(dp[i][j][k], dp[i][j-1][(k-A[i])%n]+A[i])
                else: dp[i+1][j][k] = dp[i][j][k]
    
    if dp[-1][-1][X%n]!=-1: ans = min((X-dp[-1][-1][X%n])//n, ans)
print(ans)