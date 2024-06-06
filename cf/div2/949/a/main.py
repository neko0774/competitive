T = int(input())
for i in range(T):
  l, r = map(int, input().split())
  ans = 0
  n = 1
  while n*2<=r:
    ans += 1
    n *= 2
  print(ans)