N = int(input())
A = [int(i) - 1 for i in input().split()]

left = [-1 for _ in range(N + 10)]
ans = 0
total = 0
for n, a in enumerate(A):
  if left[a] == -1:
    total += n
  else:
    total += n - left[a] - 1
  left[a] = n
  total += 1
  ans += total
print(ans)