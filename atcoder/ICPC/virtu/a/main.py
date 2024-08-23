#include<bits/stdc++.h>
def solve():
  N = int(input())
  if N == 0:exit()
  A = [int(i) for i in input().split()]
  ave = sum(A)/N
  ans = 0
  for a in A:
    if a <= ave: ans += 1
  print(ans)
while True:
  solve()