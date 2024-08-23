#include<bits/stdc++.h>
def solve():
  N = int(input())
  if N==0: exit()
  A = [int(i) for i in input().split()]
  ans = 0
  cur = A[0] + A[1]
  for i in range(2, N):
    cur += A[i]
    ans = max(ans, cur)
    cur -= A[i-2]
  print(ans)


while True:
  solve()