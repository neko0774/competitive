def solve():
  N = int(input())
  if N==0:
    exit()
  A = [int(i) for i in input().split()]
  ret = 0
  for i in range(N-3):
    if A[i]==A[i+2]==2 and A[i+1]==A[i+3]==0:
      ret += 1
  print(ret)


while True:
  solve()