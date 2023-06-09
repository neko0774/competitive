import math
A, B, C = map(int, input().split())
def f(x):
    return A*x+B*math.sin(C*x*math.pi)-100


ok = 100
ng = -1
for _ in range(300):
    mid = (ok+ng)/2
    if f(mid)<0:
        ng = mid
    else:
        ok = mid
print(ok)