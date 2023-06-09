N, Z, W = map(int, input().split())
A = [int(input(i)) for i in input().split()]

dp = [[[-1, -1] for _ in range(2)] for _ in range(N+1)]
dp[0][0][0] = Z
dp[0][0][1] = W
for n,a in enumerate(A):
    for i in range(2):
        

