P1 = [[0 for i in range(10)] for _ in range(3)]+[[1 if i=="#" else 0 for i in input()] for _ in range(4)]+[[0 for i in range(10)] for _ in range(3)]
P2 = [[1 if i=="#" else 0 for i in input()] for _ in range(4)]
P3 = [[1 if i=="#" else 0 for i in input()] for _ in range(4)]
for i in range(4):
  P1[i+3] = [0, 0, 0] + P1[i+3] + [0, 0, 0] 

cnt = 0
for y in range(10):
  for x in range(10):
    cnt += P1[y][x]

for y in range(4):
  for x in range(4):
    cnt += P2[y][x]

for y in range(4):
  for x in range(4):
    cnt += P3[y][x]

if cnt!=16:
  print("No")
  exit()


def rotate(P):
  ret = [[0 for _ in range(4)] for _ in range(4)]
  for x in range(4):
    for y in range(4):
      ret[x][3-y] = P[y][x]
  return ret

def check(P1, P2, P3, ax, ay, bx, by, flag=0):
  dup = [[0 for _ in range(10)] for _ in range(10)]
  for x in range(3, 7):
    for y in range(3, 7):
      dup[y][x] += P1[y][x]
  for x in range(4):
    for y in range(4):
      dup[ay+y][ax+x] += P2[y][x]
      if dup[ay+y][ax+x]>1: return 0
  for x in range(4):
    for y in range(4):
      dup[by+y][bx+x] += P3[y][x]
      if dup[by+y][bx+x]>1: return 0
  if flag: print(dup)
  for x in range(7):
    for y in range(7):
      cnt = 1
      for xx in range(4):
        for yy in range(4):
          if dup[y+yy][x+xx]!=1:cnt=0
      if cnt: return 1
  return 0



for i in range(4):
  for j in range(4):
    for ax in range(7):
      for ay in range(7):
        for bx in range(7):
          for by in range(7):
            if(check(P1, P2, P3, ax, ay, bx, by)):
              print("Yes")
              exit()
    P2 = rotate(P2)
  P3 = rotate(P3)
print("No")