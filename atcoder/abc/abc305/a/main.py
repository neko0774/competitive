N = int(input())

ans = 200
dif = 1000
for i in range(0, 105, 5):
    if dif>abs(i-N):
        dif = abs(i-N)
        ans = i
print(ans)