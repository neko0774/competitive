N = int(input())
X = []
Y = []
for _ in range(N):
  x, y = map(int, input().split())
  X.append(x)
  Y.append(y)

def is_triange(i, j, k):
  if X[i] == X[j] == X[k] or Y[i] == Y[j] == Y[k]: return 0
  if (Y[k] - Y[i]) * (X[j] - X[i]) == ()


ans = 0
for i in range(N):
  for j in range(i+1, N):
    for k in range(j + 1, N):
      print(dist(i, j), i, j)
      ans += is_triange(i, j, k)
print(ans)
