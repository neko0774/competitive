from random import randint as ri

for _ in range(50):
  N=ri(2,30)
  M=ri(1,30)
  print(N,M)
  A=[0]*N
  for i in range(N):A[i]=ri(1,M)
  print(*A)
print(0,0)