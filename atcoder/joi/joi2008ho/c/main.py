N, M = map(int, input().split())
P = [0]+[int(input()) for _ in range(N)]
P.sort()

S = set()
for p in P:
    for pp in P:
        if p+pp<=M: S.add(p+pp)
S = list(sorted(S))
from bisect import bisect_left as bl
ans = 0
for s in S:
    i = bl(S, M-s)
    ans = max(ans, s+S[max(0, i-1)])
print(ans)