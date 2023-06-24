while True:
  y,c,r = map(int, input().split())
  if y==c==r==0: break

  ok = 10**18
  ng = -1

  def isok(m):
    if m<=(m-c)*(100+r)//100: return 1
    for _ in range(y):
      if m<c: return 0
      m = (m-c)*(100+r)//100
    return 1

  while abs(ok-ng)>1:
    m = (ok+ng)//2
    if isok(m): ok = m
    else: ng = m
  print(ok)