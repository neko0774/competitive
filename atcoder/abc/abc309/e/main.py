N, M = map(int, input().split())
P = [int(i)-1 for i in input().split()]
nP = [[] for _ in range(N)]
for n, p in enumerate(P):
  nP[p].append(n+1)

insur = [0]*N
for _ in range(M):
  x, y = map(int, input().split())
  x -= 1
  insur[x] = max(insur[x], y+1)
from collections import deque
q = deque([[0, 0]])
cnt = [0]*N
seen = [0]*N
while q:
  x, t = q.popleft()
  seen[x] =1 
  t = max(t, insur[x])
  if t>0: cnt[x] = 1
  for nx in nP[x]:
    if not seen[nx]:
      q.append([nx, t-1])
print(sum(cnt))