INF = 10**10
from bisect import bisect_left as bl
from bisect import bisect_right as br
def solve():
  N = int(input())
  A = [int(i) for i in input().split()]

  dp = [INF for i in range(N)]
  L = [0]*N
  R = [0]*N
  for i in range(N):
    ix = bl(dp, A[i])
    L[i] = ix
    dp[ix] = A[i]

  le = bl(dp, INF)
  dp = [-1 for i in range(N)]
  for i in range(N):
    ix = br(dp, A[N-i-1])
    R[i] = N-ix
    dp[ix-1] = A[N-i-1]
  ans = []
  for i in range(N):
    if L[i]+R[N-i-1]+1==le:
      ans.append(i+1)
  print(len(ans))
  print(*ans)


T = int(input())
for i in range(T):
  solve()