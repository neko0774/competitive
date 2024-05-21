from collections import defaultdict


def solve():
  N = int(input())
  A = [int(i) for i in input().split()]

  G = defaultdict(lambda : [])
  I = defaultdict(lambda : [])

  for i, a in enumerate(A):
    G[a//4].append(a)
    I[a//4].append(i)
  
  for x in G.keys():
    G[x].sort()
    I[x].sort()
    for value, index in zip(G[x], I[x]):
      A[index] = value
  print(*A)

T = int(input())
for _ in range(T):
  solve()