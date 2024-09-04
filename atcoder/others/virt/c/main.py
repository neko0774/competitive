N, Y = map(int, input().split())

C = [10000, 5000, 1000]
for i in range(N + 1):
  for j in range(N - i + 1):
    r = N - i - j
    if Y == C[0] * i + C[1] * j + C[2] * r:
      print(i, j, r)
      exit()
print(-1, -1, -1)