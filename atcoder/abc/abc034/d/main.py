N, K = map(int, input().split())
water = []
for _ in range(N):
    w, p = map(int, input().split())
    water.append([w, p])

def check(x):
    KK = K
    conc = []
    for w, p in water:
        conc.append(w*(p-x))
    conc.sort(reverse=True)
    return sum(conc[:K])>=0

ok = 0
ng = 101
for _ in range(1000):
    m = (ok+ng)/2
    if check(m):
        ok = m
    else:
        ng = m
print(ok)