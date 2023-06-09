A, B = map(int, input().split())
from math import sqrt
ab = B**2-A**2

def check(x):


def calc(x):
    

ok = 0
ng = A*B
for _ in range(10**6):
    m = (ok+ng)/2
    if calc(m):
        ok = n
    else:
        ng = m
print(calc(ok))