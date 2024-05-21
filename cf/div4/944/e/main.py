from bisect import bisect_left as bl

def solve():
  N, K, Q = map(int, input().split())
  A = [0] + [int(i) for i in input().split()]
  B = [0] + [int(i) for i in input().split()]
  ans = []
  for _ in range(Q):
    d = int(input()) 
    if d==0:
      ans.append(0)
      continue
    i = bl(A, d)
    time = B[i-1] + (d-A[i-1])*(B[i]-B[i-1])//(A[i]-A[i-1])
    ans.append(time)
  print(*ans)
    




T = int(input())
for i in range(T):
  solve()