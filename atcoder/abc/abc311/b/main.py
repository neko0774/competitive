N, D = map(int, input().split())
ans = 0
cnt = 0
S = [[1 if i=='o' else 0 for i in input()] for _ in range(N)]
for d in range(D):
  check = 1
  for s in S:
    if not s[d]: check = 0 
  if check: cnt += 1
  else: cnt = 0
  ans = max(ans, cnt)
print(ans)