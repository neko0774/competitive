while True:
  H, W = map(int, input().split())
  if H==W==0: exit()
  E = [[int(i) for i in input().split()] for _ in range(H)]
  ans = 0


  for lx in range(W):
    for ly in range(H):
      for rx in range(lx+2, W):
        for ry in range(ly+2, H):

          total = 0
          minH = 1000000
          maxH = 0
          cnt = 0
          for x in range(lx, rx+1):
            for y in range(ly, ry+1):
              if (x==lx or x==rx) and (y==ly or y==ry):
                minH = min(minH, E[y][x])
              else:
                cnt += 1
                maxH = max(maxH, E[y][x])
                total += E[y][x]
          print(lx, ly, rx, ry, minH, maxH)
          if minH>maxH:
            ans = max(ans, cnt*minH-total)
  print(ans)