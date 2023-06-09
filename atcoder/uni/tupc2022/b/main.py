N, M, K = map(int, input().split())
wether = []
for _ in range(M):
    a, b = map(int, input().split())
    wether.append([a, b])
wether.append([N+1, 0])
snow = 0
ans = 0
lday = 1

for a,b in wether:
    day_dif = a-lday
    add = snow-K
    if add<0: add = 0
    elif day_dif<add: add=day_dif
    ans += add
    snow = max(0, snow-day_dif)
    snow += b
    lday = a
print(ans)