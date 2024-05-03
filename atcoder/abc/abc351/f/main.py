N = int(input())
A = [int(i) for i in input().split()]


def calc(A):
  ret = 0
  v = sum(A)
  N = len(A)
  for i in range(N-1):
    v -= A[-i-1]
    ret += A[-i-1]*(N-i-1)-v
  return ret

S = calc(A)
A.sort()
SS = calc(A)
print((SS+S)//2)