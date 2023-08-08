from collections import deque
def solve():
  A = deque([int(i) for i in input()][::-1])
  N = len(A)
  for i in range(N):
    if A[i]>=5:
      A[i]=0
      while i+1<N and A[i+1]==9:
        A[i+1]=0
        i+=1
        print(A)

      if(i+1==N):
        A.appendleft(1)
      else:
        A[i+1]+=1
  print(A)
  

T = int(input())
for aa in range(T):
  solve()