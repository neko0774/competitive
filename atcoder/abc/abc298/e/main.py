N, A, B, P, Q = map(int, input().split())
mod = 998244353
pinv = pow(P, mod-2, mod)
qinv = pow(Q, mod-2, mod)

dp = [[0]*(N+1) for _ in range(N+1)]
dp[A][B] = 1
#morau dp
#print(dp)
ans = 0
for i in range(N+2):
    ndp = [[0]*(N+1) for _ in range(N+1)]
    for b in range(B, N):
        #calc taka
        taka = 0
        for a in range(A+i, N):
            ndp[a][b] = pinv*taka
            taka += dp[a][b]
            if a-P>=0: taka -= dp[a-P][b]

        for a in range(max(A, N-P), N+1):
            #print(i, a, b, (P-(N-a))+1, dp[a][b])
            ans += (P-(N-a)+1)*dp[a][b]*pinv
            ndp[N][b] += (P-(N-a)+1)*dp[a][b]*pinv%mod
            ans %= mod

    dp = ndp
    #print(dp)
    ndp = [[0]*(N+1) for _ in range(N+1)]
    for a in range(A, N):
        #calc aoki
        aoki = 0
        for b in range(B+i, N+1):
            ndp[a][b] = qinv*aoki
            aoki += dp[a][b]
            if b-Q>=0: aoki -= dp[a][b-Q]
    dp = ndp
    #print(dp)
print(ans)