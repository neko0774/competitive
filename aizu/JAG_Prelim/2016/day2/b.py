while True:
  S = input()
  if S=='#':exit()
  grid = []
  m = []
  for n,s in enumerate(S):
    if s=='/':
      grid.append(m)
      m = []
      continue
    if s=='b':
      m.append(s)
    else:
      m+=['.' for _ in range(int(s))]
  grid.append(m)
  sx, sy, gx, gy = map(int, input().split())
  sx -= 1
  sy -= 1
  gx -= 1
  gy -= 1
  grid[sx][sy] = '.'
  grid[gx][gy] = 'b'

  ans = ""
  for gg in grid:
    cnt = 0
    for g in gg:
      if g=='.':
        cnt += 1
      else:
        ans += str(cnt)+'b' if cnt>0 else 'b'
        cnt = 0
    if cnt>0: ans += str(cnt)
    ans += '/'
  print(ans[:-1])