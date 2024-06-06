from random import randint
N = 3
NN = 2**N
A = [randint(0, NN) for _ in range(NN)]
L = randint(1, NN//2)
R = randint(L+1, NN)
L -= 1
R -= 1
print(N, L, R)
print(sum(A[L:R+1])%100)
print(A)
while True:
  i, j = map(int, input().split())
  l = 2**i * (j)
  r = 2**i * (j+1) -1
  print(sum(A[l:r+1])%100)