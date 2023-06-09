W, H = map(int, input().split())
N = int(input())
berrys = []
for _ in range(N):
    p, q = map(int, input().split())
    berrys.append([p, q])
AA = int(input())
A = [0]+[int(i) for i in input().split()]+[W]
BB = int(input())
B = [0]+[int(i) for i in input().split()]+[H]

from collections import defaultdict
from bisect import bisect_left as bl
cnt = defaultdict(int)
for p, q in berrys:
    x = bl(A, p)
    y = bl(B, q)
    cnt[(x, y)] += 1
mn = 0 if (AA+1)*(BB+1)>len(cnt) else min(cnt.values())
mx = max(cnt.values())
print(mn, mx)