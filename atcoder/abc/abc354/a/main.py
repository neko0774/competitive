H = int(input())

h = 0
ans = 0
for i in range(10**6):
  if h>H:
    break
  h += 2**i
  ans += 1
print(ans)