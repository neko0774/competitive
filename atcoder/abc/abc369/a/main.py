A, B = map(int, input().split())

def ok(x):
  x.sort()
  if x[0] - x[1] == x[1] - x[2]: return 1
  return 0

ans = 0
for i in range(-1000, 1000):
  ans += ok([A, B, i])
print(ans)