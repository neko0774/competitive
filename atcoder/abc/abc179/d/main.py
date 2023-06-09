N, K = map(int, input().split())
mod = 998244353
S = []
for _ in range(K):
    L, R = map(int, input().split())
    S.append([L, R+1])
S.sort()
dp = [0]*N
dp[0] = 1

accum_sum = [0]*K
for n in range(1, N):
    for i in range(K):
        if n-S[i][0]>=0: accum_sum[i] += dp[n-S[i][0]]
        if n-S[i][1]>=0: accum_sum[i] -= dp[n-S[i][1]]
    
    dp[n] += sum(accum_sum)%mod
print(dp[-1]%mod)