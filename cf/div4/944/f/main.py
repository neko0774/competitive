from math import sqrt, floor


def solve():
  r = int(input())
  ans = 0
  for x in range(1, r+1):
    one = sqrt((r+1)**2-x**2)
    non = sqrt(r**2-x**2)
    if int(one)**2==(r+1)**2-x**2:
      ans -= 1
    if int(non)**2==r**2-x**2:
      ans += 1
    #print(x, ans, one, non, floor(one)-floor(non))
    ans += floor(one)-floor(non)
  print(ans*4) 



T = int(input())
for _ in range(T):
  solve()