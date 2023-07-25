N, M = map(int, input().split())
dxy = [[0, 1], [1, 0], [-1, 0], [0, -1]]
S = [[1 if i=='.' else 0 for i in input()] for _ in range(N)]
from collections import deque
q = deque([[1, 1]])
visited = [[0 for _ in range(M)] for _ in range(N)]
visited[1][1] = 1
while q:
  x, y = q.popleft()
  for i, j in dxy:
    nx = x
    ny = y
    while S[ny+j][nx+i]:
      visited[ny][nx] = 1
      nx += i
      ny += j
    if not visited[ny][nx]:
      visited[ny][nx] = 1
      q.append([nx, ny])
ans = 0
for i in visited:
  ans += sum(i)
print(ans)