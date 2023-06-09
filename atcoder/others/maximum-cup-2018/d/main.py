N, M, L, X = map(int, input().split())
A = [int(i) for i in input().split()]

#the number of minimum cycles using {A[:i]} tanks, given jth place
dp = [[10**12]*M for _ in range(N+1)]
dp[0][0] = 1

for i in range(N):
    for m in range(M):
        if m-A[i]>=0:
            dp[i+1][m] = min(dp[i][m], dp[i][m-A[i]])
        else:
            dp[i+1][m] = min(dp[i][m], dp[i][(m-A[i])%M]+abs(m-A[i])//M+1)
#print(dp)
print("Yes" if dp[-1][L]<X else "No")