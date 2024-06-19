N = int(input())
ans = [["." for _ in range(pow(3, N))] for _ in range(pow(3, N))]

def solve(N, x, y):
  if N==0:
    ans[y][x] = "#"
    return
  for i in range(3):
    for j in range(3):
      if i==1 and j==1: continue
      solve(N-1, x+pow(3, N-1)*i, y+pow(3, N-1)*j)

solve(N, 0, 0)
for a in ans:
  print(*a, sep='')