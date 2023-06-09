N = int(input())
baloon = [[int(i) for i in input().split()] for _ in range(N)]
from collections import defaultdict
def is_ok(x):
    count = defaultdict(int)
    for h,s in baloon:
        if h>x: return False
        count[min((x-h)//s, N+1)] += 1
    accum = -1
    for t,n in sorted(count.items()):
        accum += n
        if accum>t: return False
    return True

ok, ng = 10**15, -1
while abs(ok-ng)>1:
    mid = (ok+ng)//2
    if is_ok(mid):
        ok = mid
    else:
        ng = mid
print(ok)