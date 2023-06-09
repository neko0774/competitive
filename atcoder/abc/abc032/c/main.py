N, K = map(int, input().split())
S = [int(input()) for _ in range(N)]
if min(S)==0:
    print(N)
    exit()

l = 0
ans = 0
num = S[0]
for r in range(1, N):
    num *= S[r]
    while l<=r and num>K:
        num //= S[l]
        l += 1
    ans = max(ans, r-l+1)
print(ans) 