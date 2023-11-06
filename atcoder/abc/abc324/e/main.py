from collections import Counter
from bisect import bisect_left as bl
from bisect import bisect_right as br

N, T = input().split()
N = int(N)
S = [input() for _ in range(N)]

from_front = []
from_back = []

for s in S:
  t_front = 0
  for ss in s:
    if t_front<len(T) and T[t_front]==ss:
      t_front+=1
  from_front.append(t_front)
  t_back = 0
  for ss in s[::-1]:
    if t_back<len(T) and T[-t_back-1]==ss:
      t_back+=1
  from_back.append(t_back)

ans = 0
from_back.sort()
for f in from_front:
  i = bl(from_back, len(T)-f)
  ans += N-i
print(ans)