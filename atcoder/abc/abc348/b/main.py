N = int(input())
S = []
for _ in range(N):
  x, y = map(int, input().split())
  S.append([x, y])

for i in range(N):
  d = -1
  ans = -1
  x = S[i][0]
  y = S[i][1]
  for j, (nx, ny) in enumerate(S):
    if ((x-nx)**2+(y-ny)**2)**(1/2)>d:
      d = ((x-nx)**2+(y-ny)**2)**(1/2)
      ans = j+1
  print(ans)