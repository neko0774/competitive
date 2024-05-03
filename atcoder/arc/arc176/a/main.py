N, M = map(int, input().split())
ans = set()
low = [0]*N
col = [0]*N
org = set()
to_add = set([i for i in range(N)])
for _ in range(M):
  x, y = map(int, input().split())
  ans.add((x, y))
  org.add((x, y))
  x -= 1
  y -= 1
  low[x] += 1
  col[y] += 1
  if low[x]>=M:
    to_add.discard(x)

for y in range(N):
  cnt = col[y]
  todelete=[]
  for v in to_add:
    if col[y]>=M: break
    if (v+1, y+1) in ans: continue
    low[v] += 1
    if low[v]>=M:
      todelete.append(v)
    ans.add((v+1, y+1))
    col[y] += 1
  for vv in todelete:
    to_add.discard(vv)
xx = []
for i in range(N):
  while(low[i]<M):
    xx.append(i+1)
    low[i] += 1
yy = []
for i in range(N):
  while(col[i]<M):
    yy.append(i+1)
    col[i] += 1
#print(len(ans))
#print(low, col)
#print(xx, yy)
adding = set()
deleting = set()
if len(ans)!=M*N:
  for x, y in ans:
    if not xx: break
    if not (x, yy[-1]) in ans and not (xx[-1], y) in ans and not (xx[-1], y) in adding and not (x, yy[-1]) in adding and not (x, y) in org:
      deleting.add((x, y))
      adding.add((x, yy.pop()))
      adding.add((xx.pop(), y))
      
for x, y in deleting:
  ans.discard((x, y)) 
for x, y in adding:
  ans.add((x, y))
      


print(len(ans))
l = []
f = []
for a in ans:
  print(*a)
  l.append(a[0])
  f.append(a[-1])
from collections import Counter
#print(Counter(l).values(), Counter(f).values())