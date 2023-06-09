N, X = map(int, input().split())
W = [int(input()) for _ in range(N)]
from collections import Counter

wf = W[:N//2]
wb = W[N//2:]
sf, sb = [0], [0]
for w in wf:
    nsf = sf[:]
    for s in sf:
        nsf.append(s+w)
    sf = nsf
for w in wb:
    nsb = sb[:]
    for s in sb:
        nsb.append(s+w)
    sb = nsb

sb = Counter(sb)
ans = 0
for s in sf:
    ans += sb[X-s]
print(ans)