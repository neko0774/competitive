N, X = map(int, input().split())
L = []
for _ in range(N):
  L.append([int(i) for i in input().split()])

cur = 1
ans = 0
def dfs(depth):
  global cur, ans
  if cur>X:
    return
  if cur == X and depth ==N:
    ans += 1
  if depth == N:
    return
  for l in L[depth][1:]:
    cur *= l
    dfs(depth+1)
    cur //=l
dfs(0)
print(ans)