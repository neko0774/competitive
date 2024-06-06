from random import randint as rd
N = 100
for i in range(N):
  s = rd(0, 100)
  print(s, rd(0, 1000-s-5))