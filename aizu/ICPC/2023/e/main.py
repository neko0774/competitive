while True:
  N = int(input())
  if N==0: exit()
  dp = [[[-1, -1] for _ in range(2*N+1)] for _ in range(N+1)]
  dp[0][0] = [N-1, N-1]
  for i in range(1, N+1):
    X,Y = map(int, input().split())
    for j in range(2*N+1):
      x = -1
      y = -1
      if j-2>=0:
        x, y = dp[i-1][j-2][0], dp[i-2][j-2][1]
      if j-1>=0:
        lx = dp[i-1][j-1][0]
        ly = dp[i-1][j-1][1]
        if ly<Y and lx<X:
          pass
        elif ly==Y:
          if Y>y:
            y = Y
            x = lx
          elif Y==y:
            x = max(x, lx)
        elif lx>=X:
          if ly>y:
            y = ly
            x = X
          elif ly==y:
            x = max(x, lx)
      lx = dp[i-1][j][0]
      ly = dp[i-1][j][1]
      if ly>y:
        y = ly
        x = ly
      elif ly==y:
        x = max(x, lx)
      dp[i][j] = [x, y]
    print(dp)
  for i in range(2*N+1):
    if dp[-1][i][0]>=0 and dp[-1][i][1]>=0:
      print(i)
      break
           


      
      

    