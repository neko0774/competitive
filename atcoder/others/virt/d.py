import itertools as it
K = int(input())

lis = []
for iter in it.product([0, 1], repeat = 10):
  pos = []
  for n in range(10)[::-1]:
    if iter[n]:
      pos.append(n)
  if pos: lis.append(int("".join(map(str, pos))))
lis.sort()
print(lis[K])