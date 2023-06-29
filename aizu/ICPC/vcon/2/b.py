from bisect import bisect_left as bl
while True:
  N, M = map(int, input().split())
  if N==M==0:exit()

  C = [int(input()) for _ in range(M)]
  C.sort()
  X = [int(input()) for _ in range(N)]
  inf = 10**12

  dp = [[inf]*270 for _ in range(N+1)]
  dp[0][128] = 0
  for n in range(N):
    for d in range(260):
      for m in C:
        if d+m>255: c = 255
        elif d+m<0: c = 0
        else: c = d+m
        dp[n+1][c] = min(dp[n+1][c], dp[n][d]+(X[n]-c)**2)
  print(min(dp[-1]))