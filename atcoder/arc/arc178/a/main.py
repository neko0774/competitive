N, M = map(int, input().split())
A = [int(i) for i in input().split()]
A.sort()


if A[0]==1 or A[-1]==N:
  print(-1)
  exit()
reach = 0
ans = []
for i in range(N):
  if
