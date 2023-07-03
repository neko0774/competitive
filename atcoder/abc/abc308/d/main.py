H, W = map(int, input().split())
S = [[i for i in input()] for _ in range(H)]

from collections import deque
q = deque([[0, 0, 's']])
nxt = ['s', 'n', 'u', 'k', 'e']
nxt = {'s':'n', 'n':'u', 'u':'k', 'k':'e', 'e':'s'}
if not S[0][0]=='s':
  print("No")
  exit()
seen = [[0]*W for _ in range(H)]
seen[0][0] = 1
while q:
  x, y, let = q.popleft()
  if x==W-1 and y==H-1:
    print("Yes")
    exit()
  for i, j in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
    nx = x+i
    ny = y+j
    #print(nx, ny, S[ny][nx])
    if 0<=nx<W and 0<=ny<H and S[ny][nx]==nxt[let] and not seen[ny][nx]:
      seen[ny][nx] = 1
      q.append([nx, ny, S[ny][nx]])

print("No")