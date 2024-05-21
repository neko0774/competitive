import random
print(10)
for i in range(10):
  L = [i for i in range(1, 101)]
  random.shuffle(L)
  print(len(L))
  print(*L)