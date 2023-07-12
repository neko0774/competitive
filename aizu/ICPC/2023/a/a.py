while True:
  N = int(input())
  if N==0: exit()
  A = [int(i) for i in input().split()]
  dif = 10**9
  ans = -1
  for n, a in enumerate(A):
    if dif>abs(a-2023):
      dif = abs(a-2023)
      ans = n+1
  print(ans)