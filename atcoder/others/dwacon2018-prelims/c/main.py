N, M = map(int, input().split())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]

from collections import Counter
mod = 10**9+7
AA = sum(A)
BB = sum(B)
CA = Counter(A)
CB = Counter(B)
L = max(max(CA.values()), max(CB.values()))
P = dict()
for a in range(max(AA, BB)+1):
    for b in range(1, L+1):
        if a==0 or b==1:
            P[(a,b)] = 1
        elif a-b<0:
            P[(a,b)] = P[(a, a)]
        else:
            P[(a,b)] = P[(a, b-1)]+P[(a-b,b)]
        P[(a,b)]%=mod

def solve(A, AA, C):
    dp = [[0]*(AA+1) for _ in range(len(C)+1)]
    dp[0][0] = 1 
    for i,x in enumerate(C.values()):
        for j in range(AA+1):
            for l in range(AA+1-j):
                dp[i+1][j+l] += dp[i][j]*P[(l, x)]
                dp[i+1][j+l] %= mod
    return dp[-1][-1]
print(solve(A, BB, CA)%mod*solve(B, AA, CB)%mod)