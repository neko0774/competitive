N = int(input())
l = -1
r = -1
ans = 0
for i in range(N):
  A, S = input().split()
  A = int(A)
  if S == 'L':
    if l != -1:
      ans += abs(l - A)
    l = A
  else:
    if r != -1:
      ans += abs(r - A)
    r = A
print(ans)