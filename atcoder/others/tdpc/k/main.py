N = int(input())
circles = []
memo = dict()
inf = 10**18
for _ in range(N):
    x, r = map(int, input().split())
    if x-r in memo:
        memo[x-r].append(x+r)
    else:
        memo[x-r] = [x+r]
for x in sorted(memo.keys(), reverse=True):
    memo[x].sort(reverse=True)
    circles += memo[x]
from bisect import bisect_left as bl
dp = [inf]*N
for c in circles:
    dp[bl(dp, c)] = c
print(bl(dp, inf))