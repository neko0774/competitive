N, Q = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(N-1):
  u, v = map(int, input().split())
  u -= 1
  v -= 1
  