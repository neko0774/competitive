N = int(input())
A = [int(input()) for _ in range(N)]
from collections import deque
AA = deque([0])
for a in A:
    AA.append(a+AA[-1])
print(AA)
from bisect import bisect_left as bl

def check(x):
    A = AA.copy()
    dif = 0
    for i in range(N):
        tmp = A[-1]
        dif += tmp
        A.append(tmp+A.popleft())
        dif2 = 0
        clear = 
        for _ in range(3):
            i = bl(A, x-dif+dif2)
            if i==N+1:
                clear = 0
                break
            dif2 += A[i]
        if clear: return True

            


ok = 0
ng = 10**15
while abs(ok-ng)>1:
    m = (ok+ng)//2
    if check(m):
        ok = m
    else:
        ng = m
print(ok)