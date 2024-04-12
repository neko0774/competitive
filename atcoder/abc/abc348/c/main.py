N = int(input())
beans = dict()

for i in range(N):
  a, c = map(int, input().split())
  if c in beans:
    beans[c] = min(beans[c], a)
  else:
    beans[c] = a
ans = 0
print(max(beans.values()))