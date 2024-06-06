T = int(input())
for i in range(T):
  N, M = map(int, input().split())
  r = N+M
  l = max(1, N-M)
  bit = 40
  ans = 0
  for i in range(bit):
    if N&(1<<i):
      ans |= 1<<i
    elif N<=(1<<i):
      if (1<<i)<=r: ans |= (1<<i)
    else:
      ls = N%(1<<i)
      nx = (1<<i) - ls
      if N+nx<=r: ans |= (1<<i)
      if l<=N-ls-1: ans |= (1<<i)
  print(ans)