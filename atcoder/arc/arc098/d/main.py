N = int(input())
A = [int(i) for i in input().split()]

def check(n, x):
    for i in range(20):
        if n>>i&1 and x>>i&1: return False
    return True


l = 0
n = 0
ans = 0
for r in range(N):
    while l<=r and not check(n, A[r]):
        n ^= A[l]
        l += 1
    n ^= A[r]
    ans += r-l+1

print(ans)