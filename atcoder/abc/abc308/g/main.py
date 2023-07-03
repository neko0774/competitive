from collections import defaultdict
Q = int(input())
BB = defaultdict(int)
for _ in range(Q):
  q = input()
  if q[0]=='1':
    _,x = map(int, q.split())
    BB[x] += 1
  elif q[0]=='2':
    _,x = map(int, q.split())
    BB[x] -= 1
  else:
