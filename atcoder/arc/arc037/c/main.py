N, K = map(int, input().split())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]

B.sort()
from bisect import bisect_right as br
from math import ceil
def check(x):
    cnt = 0
    for a in A:
        cnt += br(B, x//a)
        #print(a, cnt)
    return cnt>=K
        



ok = 10**18
ng = -1
while abs(ok-ng)>1:
    m = (ok+ng)//2
    if check(m): ok = m
    else: ng= m
print(ok)