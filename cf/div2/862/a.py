def solve():
  N = int(input())
  A =  [int(i) for i in input().split()]
  ans = 0
  for a in A:
    ans = ans ^ a

  if N % 2 == 0:
    if ans != 0: print(-1)
    else: print(ans)
  else:
    print(ans)

n = int(input())
for _ in range(n):
  solve()