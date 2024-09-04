N, K = map(int, input().split())

ans = 0
for i in range(1, N + 1):
  c = 0
  while i < K:
    c += 1
    i *= 2
  ans += 1 / pow(2, c)
print(ans / N)