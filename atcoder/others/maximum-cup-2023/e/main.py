class BIT:
  def __init__(self, N):
    self.size = N
    self.data = [0]*(N+1)
  

  def sum(self, r):
    s = 0
    while r>0:
      s += self.data[r]
      r -= r&-r
    return s
  
  def add(self, i, x):
    while i<=self.size:
      self.data[i] += x
      i += i&-i 


def compress(A):
  #input array and compres it
  s = {j:i+1 for i,j in enumerate(sorted(list(i for i in set(A))))}
  return [s[i] for i in A]

def cnt_inv(A, N=0):
  if N==0:
    N = len(A)
  bit = BIT(N)
  s = N*(N-1)//2
  B = [0]*N

  A = compress(A)

  for i in A:
    s -= bit.sum(i)
    bit.add(i, 1)
  return s


def grd(N, A):
  cnt = 0
  for i in range(N):
    for j in range(i+1, N):
      if A[i] > A[j]:
        A[i], A[j] = A[j], A[i]
        cnt += 1
  print(cnt)
  print(A)





def test(N):
  import random as rd
  for i in range(N):
    A = [rd.randint(1, 1000) for i in range(10)]
    main(10, A.copy())
    grd(10, A)


N = int(input())
P = [int(i) for i in input().split()]
print(cnt_inv(P))