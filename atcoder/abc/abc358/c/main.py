N, M = map(int, input().split())
S = [[i for i in input()] for _ in range(N)]
import itertools as it

ans = N
for iter in it.product([0, 1], repeat=N):
  corns = [0]*M
  for j in range(N):
    if iter[j]:
      for k in range(M):
        if S[j][k]=='o':
          corns[k] = 1
  if sum(corns)==M:
    ans = min(ans, sum(iter))
print(ans)