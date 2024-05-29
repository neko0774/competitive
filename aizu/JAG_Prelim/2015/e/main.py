def solve():
  D, E = map(int, input().split())
  if D==0 and E==0:
    exit()
  
  ans = 10**9
  for x in range(110):
    for y in range(110):
      if x+y==D: ans = min(ans, abs((x**2+y**2)**(1/2)-E))
  print(ans)

while True:
  solve()