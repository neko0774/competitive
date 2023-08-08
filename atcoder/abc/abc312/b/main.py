H, W = map(int, input().split())
S = [[i for i in input()] for _ in range(H)]

def check(x, y):
  for i in range(4):
    for j in range(4):
      if i==3 or j==3:
        if S[y+j][x+i]!='.': return 0
      elif S[y+j][x+i]!='#': return 0
  x += 5
  y += 5
  for i in range(4):
    for j in range(4):
      if i==0 or j==0:
        if S[y+j][x+i]!='.': return 0
      elif S[y+j][x+i]!='#': return 0
  return 1

for y in range(H-8):
  for x in range(W-8):
    if check(x, y): print(y+1, x+1)