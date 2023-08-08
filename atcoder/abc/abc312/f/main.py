from collections import deque
from heapq import heappush, heappop
N, M = map(int, input().split())
opener = []
can1 = []
can2 = []
for _ in range(N):
  T, X = map(int, input().split())
  if T==0: can1.append(X)
  elif T==2: opener.append(X)
  else: can2.append(X)

can1.sort(reverse=True)
can2.sort(reverse=True)
opener.sort(reverse=True)

can1 = deque(can1)
can2 = deque(can2)
ans = 0
hold = []
hap = 0
for i in range(M):
  if can1:
    heappush(hold, can1[0])
    hap += can1.popleft()
  else:
    heappush(hold, 0)
ans = hap 
for c in opener:
  if len(hold)==0: break
  hap -= heappop(hold)
  for i in range(c):
    if len(can2)==0 or len(hold)==0: break
    n = heappop(hold)
    if can2[0]>n:
      heappush(hold, can2[0])
      hap += can2.popleft()
      hap -= n
  ans = max(ans, hap)
print(ans)