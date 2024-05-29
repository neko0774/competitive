N  = int(input())
pos = [[int(i) for i in input().split()] for _ in range(N)]
ans = 0
for x, y in pos:
  for xx, yy in pos:
    ans = max(ans, ((xx-x)**2+(y-yy)**2)**(1/2))
print(ans)