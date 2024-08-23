#include<bits/stdc++.h>
from collections import defaultdict

def solve():
  N = int(input())
  if N == 0: exit()
  A = [int(i) for i in input().split()]
  cur = 0
  for a in A:
    if cur + a > 300:
      continue
    cur += a
  print(cur)



while True:
  solve()