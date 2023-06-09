R, B = map(int, input().split())
x, y = map(int, input().split())

def check(k):
    if k>R or k>B: return False
    return (R-k)//(x-1)+(B-k)//(y-1)>=k

ok = 0
ng = 10**18
while abs(ok-ng)>1:
    m = (ok+ng)//2
    if check(m):
        ok = m
    else:
        ng = m
print(ok)