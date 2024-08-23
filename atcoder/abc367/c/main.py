import itertools as it
N, K = map(int, input().split())
R = [int(i) for i in input().split()]


size = 5 ** N
ans = []
for c in range(size):
  memo = []
  total = 0
  for r in R:
    if c % 5 + 1 <= r:
      memo.append(c % 5 + 1)
      total += c % 5 + 1
      c //= 5
    else:
      break
  if len(memo) == N and total % K == 0:
    ans.append(memo)
ans.sort()

for a in ans:
  print(*a)