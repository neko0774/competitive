from random import randint as rd
C = 1000
ma = 10**9
for i in range(1):
  N = rd(1, C)
  print(N)
  for i in range(N):
    x = rd(0, ma)
    y = rd(0, ma)
    print(x, y)