H, W = map(int, input().split())
A = [[int(i) for i in input().split()] for _ in range(H)]
acc = [[0 for _ in range(W + 1)] for _ in range(H + 1)]


for y in range(H):
  for x in range(W):
    acc[y + 1][x + 1] = A[y][x]
for y in range(H + 1):
  for x in range(W):
    acc[y][x + 1] += acc[y][x]

for x in range(W + 1):
    for y in range(H):
      acc[y + 1][x] += acc[y][x]
ans = 0
for y in range(H):
  for x in range(W):
    for w in range(1, 11):
      for h in range(1, 11):
        if y + h > H or x + w > W: break
        if acc[y + h][x + w] - acc[y][x + w] - acc[y + h][x] + acc[y][x] == 10: ans += 1
        #print(x, y, x + h, y + h, acc[y + h][x + w] - acc[y][x + w] - acc[y + h][x] + acc[y][x])
print(ans)