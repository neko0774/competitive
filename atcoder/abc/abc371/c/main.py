N = int(input())
Mg = int(input())
Gg = [[0 for _ in range(N)] for _ in range(N)]
for _ in range(Mg):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  Gg[a][b] = 1
  Gg[b][a] = 1


Mh = int(input())
Gh = [[0 for _ in range(N)] for _ in range(N)]
for _ in range(Mh):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  Gh[a][b] = 1
  Gh[b][a] = 1

A = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N - 1):
  A[i][i+1:] = [int(i) for i in input().split()]
import itertools as it
ans = 10**12
for iter in it.permutations(range(N)):
  memo = 0
  for u in range(N):
    for v in range(u + 1, N):
      nu, nv = min(iter[u], iter[v]), max(iter[u], iter[v])
      if Gg[u][v] != Gh[nu][nv]:
        memo += A[nu][nv]
  ans = min(ans, memo)
print(ans)