from math import ceil
while True:
  x ,y, s = map(int, input().split())
  if x==y==s: exit()
  ans = 0
  for ss in range(1, s//2+1):
    f = ss
    b = s-ss
    ff = ceil(100*(f+1)/(100+x))-1
    bb = ceil(100*(b+1)/(100+x))-1
    if (ff*(100+x)//100)+(bb*(100+x)//100)!=s: continue
    nv = (ff*(100+y)//100)+(bb*(100+y)//100)
    #print(nv, ff, bb, f, b)
    ans = max(nv, ans)
  print(ans)
    