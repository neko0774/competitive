N, Q = map(int, input().split())
C = [set([i]) for i in input().split()]

for i in range(Q):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  C[b] |= C[a]
  C[a] = set()
  print(len(C[b]))