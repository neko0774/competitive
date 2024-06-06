N, M, K = map(int, input().split())
T = [[i for i in input().split()] for _ in range(M)]

KEYS = []
for i in range(M):
  if T[i][-1]=='o':
    KEYS.append(T[i][1:-1])
  else:
    ks = set([i+1 for i in range(N)])
    for k in T[i][1:-1]:
      ks.discard(int(k))
    KEYS.append([i for i in ks])
print(KEYS)
ans = 0
import itertools as it
for iter in it.product([0, 1], repeat=N):
  if sum(iter)<K:
    continue
  ok = 1
  for j in range(M):
    cnt = int(T[j][0])
    if T[j][-1]=='o':
      k = 0
      for i in range(cnt):
        key = int(T[j][i+1])-1
        if iter[key]: k += 1
      if k<K:
        ok = 0
    else:
      memo = 1
      for k in KEYS[j]:
        if iter[k]==1:
          memo = 0
      ok = max(0, ok-memo)
    if not ok: break
  if ok: print(iter)
  ans += ok
print(ans)