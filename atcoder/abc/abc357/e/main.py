N = int(input())
A = [int(i)-1 for i in input().split()]
rev = [[] for _ in range(N)]
for i, a in enumerate(A):
  rev[a].append(i)

ans = 0
seen = [0]*N
cnt = [0]*N

cycle = set()
for cur in range(N):
  if seen[cur]: continue
  num = cur+1
  while seen[cur]==0:
    seen[cur] = num
    cur = A[cur]
  if seen[A[cur]] == num: cycle.add(A[cur]) 

count = [0]*N
start = []
cc = set()
for cur in cycle:
  if count[cur]!=0: continue
  start.append(cur)
  cnt = set()
  while not cur in cnt:
    cnt.add(cur)
    cc.add(cur)
    cur = A[cur]
  for c in cnt:
    count[c] = len(cnt)

seen = [0]*N
from collections import deque
for s in start:
  q = deque()
  q.append(s)
  while q:
    x = q.popleft()
    seen[x] = 1
    for nx in rev[x]:
      if seen[nx]: continue
      q.append(nx)
      if x in cc and nx in cc:
        continue
      else:
        count[nx] += count[x]+1
print(sum(count))