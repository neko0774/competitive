H, W = map(int, input().split())
S = [[1 if i=='#' else 0 for i in input()] for _ in range(H)]

dp = [[[0, 0] for _ in range(W+1)] for _ in range(H+1)]#black, white
for y in range(H):
  dp[y][-1] = [1, 0]
for x in range(W):
  dp[-1][x] = [1, 0]

