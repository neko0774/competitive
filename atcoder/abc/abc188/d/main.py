N, C = map(int, input().split())
event = []
for _ in range(N):
    a,b,c = map(int, input().split())
    event.append([a,c])
    event.append([b+1,-c])

event.sort()
ans = 0
current_price = 0
last_day = 0
for d,c in event:
    ans += min(C, current_price)*(d-last_day)
    last_day = d
    current_price += c
print(ans)