import sys
sys.setrecursionlimit(10**5)
A = [[int(i) for i in input().split()] for _ in range(3)]
B = [[0 for _ in range(3)] for _ in range(3)]


def to_end(x):
  aoki = 0
  takahashi = 0

  for i in range(3):
    check = True
    for j in range(2):
      if B[i][j]==0 or B[i][j+1]!=B[i][j]:
        check = False
    if check: return B[i][j]

  for j in range(3):
    check = True
    for i in range(2):
      if B[i][j]==0 or B[i+1][j]!=B[i][j]:
        check = False
    if check: return B[i][j]

  if B[0][0]==B[1][1]==B[2][2] and B[0][0]!=0:
    return B[0][0]
  if B[0][2]==B[1][1]==B[2][0] and B[0][2]!=0:
    return B[0][2]

  for i in range(3):
    for j in range(3):
      if B[i][j] == 0: return 0
      if B[i][j] == 1: takahashi += A[i][j]
      else: aoki += A[i][j]
  return 1 if takahashi>aoki else -1

def dfs(turn):
  if to_end(turn):
    return to_end(turn)
  ret = -1*turn
  for i in range(3):
    for j in range(3):
      if B[i][j]!=0: continue
      B[i][j] = turn
      if dfs(-1*turn)==turn:
        ret = turn
      B[i][j] = 0
  return ret

print("Takahashi" if dfs(1)==1 else "Aoki")