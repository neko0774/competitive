N = int(input())
A = [int(i) for i in input().split()]

ans = 0
#if ith is 0 or 1
#then used or not 
#maximum
dp = [[0, 0], [0, 0]]

for a in A:
    ndp = [[0, 0], [0, 0]]
    ndp[0][0] = max(dp[0][0])
    