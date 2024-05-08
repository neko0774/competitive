N, Q = map(int, input().split())
P = [[0 if i=="W" else 1 for i in input()] for _ in range(N)]
unit = 0
for a in P:
  unit += sum(a)

number = [[0 for _ in range(N+1)] for _ in range(N+1)]
for x in range(1,N+1):
  for y in range(1,N+1):
    number[y][x] = number[y-1][x]+number[y][x-1]-number[y-1][x-1]+P[y-1][x-1]


def dim2_imos(lx, ly, rx, ry):
  #return [lx, rx) * [ly, ry)
  return number[ry][rx]-number[ry][lx]-number[ly][rx]+number[ly][lx]

for _ in range(Q):
  ans = 0
  lx, ly, rx, ry = map(int, input().split())
  row = rx//N-(lx+N-1)//N
  col = ry//N-(ly+N-1)//N
  rx += 1
  ry += 1
  rx %= N
  ry %= N
  lx %= N
  ly %= N
  ans += unit*row*col
  ans += dim2_imos(0, 0, rx, ry) + dim2_imos(lx, ly, N, N) + dim2_imos(0, ly, rx, N) + dim2_imos(lx, 0, N, ry)
  print(row, col, dim2_imos(0,0,rx,ry), dim2_imos(lx, ly, N, N), dim2_imos(0, ly, rx, N), dim2_imos(lx, 0, N, ry))
  ans += (dim2_imos(0, ly, N, N) + dim2_imos(0, 0, N, ry))*row + (dim2_imos(lx, 0, N, N) + dim2_imos(0, 0, rx, N))*col
  print(ans) 
  