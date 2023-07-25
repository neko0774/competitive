H, W, N = map(int, input().split())
count = [[0 for _ in range(W+1)] for _ in range(H+1)]
for _ in range(N):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  count[a][b] += 1

