import sys
input = sys.stdin.readline
def solve():
    X = input().rstrip()
    Y = input().rstrip()
    xx, yy = len(X), len(Y)
    dp = [0 for _ in range(xx+1)]
    for y in range(yy):
        memo = dp[:]
        for x in range(xx):
            if X[x]==Y[y]: dp[x+1] = memo[x]+1
            elif dp[x]>dp[x+1]: dp[x+1] = dp[x]
    return dp[xx]
Q = int(input())
for _ in range(Q):
    print(solve())