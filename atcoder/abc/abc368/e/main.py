N, M, x = map(int, input().split())
G = [[] for _ in range(N)]
trains = [[[], []] for _ in range(N)]
for i in range(M):
  A, B, S, T = map(int, input().split())
  A -= 1
  B -= 1
  if i == 0:
    s = B
  trains[A][0].append((S, i, B))
  trains[B][1].append((T, i, A))
  G[A].append((B, S, T))
  G[B].append((A, S, T))

for i in range(N):
  trains[i][0].sort()
  trains[i][1].sort()

INF = 10 ** 18
X = [INF] * N
X[0] = x

