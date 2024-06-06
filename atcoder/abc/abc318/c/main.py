N, D, P = map(int, input().split())
F = [int(i) for i in input().split()]
F.sort(reverse=True)
total = sum(F)
ticket = 0
cur = D-1
ans = sum(F)
for i in range(N):
  cur += 1
  total -= F[i]
  if cur>=D:
    cur = 0
    ticket += P
  ans = min(ans, total+ticket)
print(ans)