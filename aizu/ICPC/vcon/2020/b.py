from collections import deque
dxy = [[0, 1], [1, 0], [-1, 0], [0, -1]]
while True:
  W, H, N, D, B = map(int, input().split())
  B -= 1
  if W==0:exit()
  BOM = []
  place = set()
  for i in range(N):
    x, y = map(int, input().split())
    if i==B: q = deque([[x, y]])
    else: place.add((x, y))
  
  cnt = 1
  #print(place)
  while q:
    x, y = q.popleft()
    for i, j in dxy:
      nx = x
      ny = y
      for d in range(D):
        nx += i
        ny += j
        #print(nx, ny)
        if not 0<nx<=W or not 0<ny<=H: break
        if (nx, ny) in place:
          q.append((nx, ny))
          place.discard((nx, ny))
          #print((nx, ny))
          cnt += 1
  print(cnt)