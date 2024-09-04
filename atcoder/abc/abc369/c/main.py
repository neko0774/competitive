N = int(input())
A = [int(i) for i in input().split()]

if N == 1:
  print(1)
  exit()

to_add = [1]
for i in range(2, N + 4):
  to_add.append(to_add[-1] + i)
v = A[0]
d = -1
count = []
cur = 0
for a in A[1:]:
  if a - v == d:
    cur += 1
  else:
    if cur: count.append(cur)
    d = a - v
    cur = 1
  v = a
count.append(cur)

ans = N
for c in count:
  ans += to_add[c - 1]
print(ans)