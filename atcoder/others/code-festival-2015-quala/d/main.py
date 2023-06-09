N, M = map(int, input().split())
X = [int(input())-1 for _ in range(M)]
def is_ok(t):
    cur = 0
    for x in X:
        if x<=cur:
            cur = x+t+1
        elif x-cur>t:
            return False
        else:
            c1 = x+(t-(x-cur))//2+1
            c2 = x+t-(x-cur)*2+1
            cur = max(c1, c2)
    return cur>N

ok = 2*N
ng = -1
while abs(ok-ng)>1:
    mid = (ok+ng)//2
    if is_ok(mid):
        ok = mid
    else:
        ng = mid
print(ok)