H, W = map(int, input().split())
M1 = [[i for i in input()] for _ in range(H)]
M2 = [[i for i in input()] for _ in range(H)]

def is_same(M1, M2):
  for h in range(H):
    for w in range(W):
      if M1[h][w] != M2[h][w]: return 0
  return 1

def row_shift(M):
  ret = [[0] * W for _ in range(H)]
  for h in range(H):
    for w in range(W):
      ret[(h + 1) % H][w] = M[h][w]
  return ret

def col_shift(M):
  ret = [[0] * W for _ in range(H)]
  for w in range(W):
    for h in range(H):
      ret[h][(w + 1) % W] = M[h][w]
  return ret

for h in range(H):
  M1 = row_shift(M1)
  for w in range(W):
    M1 = col_shift(M1)
    if is_same(M1, M2):
      print("Yes")
      exit()
print("No")