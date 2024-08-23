N = int(input())
X = [0] * N
Y = [0] * N
for i in range(N):
  X[i], Y[i] = map(int, input().split())

ans = 0
def judge(i, j, k):
  if X[i] == X[j] == X[k] or Y[i] == Y[j] == Y[k]: return 0
  if (Y[k] - Y[i]) * (X[j] - X[i]) == (Y[j] - Y[i]) * (X[k] - X[i]): return 0
  return 1
for i in range(N):
  for j in range(i + 1, N):
    for k in range(j + 1, N):
      ans += judge(i, j, k)
print(ans)