N, K = map(int, input().split())
A = [int(input()) for _ in range(N)]
if sum(A)==K:
    print(1)
    exit()


#the minimum wins needed given at ith day and  jth days of feeling good
dp = [[10**18]*(N+1) for _ in range(N+1)]
dp[-1][0] = 0
aa = 0
import math
for i in range(N):
    dp[i][0] = 0
    for j in range(1,i+2):
        if dp[i][j-1]==0:
            dp[i+1][j] = 1
        else:
            dp[i+1][j] = min(dp[i][j], ((A[i]+aa)*dp[i][j-1])//aa+1)
    aa += A[i]
for i in range(N+1)[::-1]:
    if dp[-1][i]<=K:
        print(i)
        exit()
