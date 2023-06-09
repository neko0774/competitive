N = int(input())
A = [int(i) for i in input().split()]
M = int(input())
B = set(int(i) for i in input().split())
X = int(input())

dp = [0]*(X+1)
dp[0] = 1
for i in range(X+1):
    if i in B or dp[i]==0: continue
    for a in A:
        if i+a<X+1: dp[i+a] |= dp[i]
print("Yes" if dp[-1] else "No")