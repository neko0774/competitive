N = int(input())
S = [input() for _ in range(N)]

M = int(input())
T = [input() for _ in range(M)]

ans = 0
word = set()
for s in S:
  word.add(s)
for s in T:
  word.add(s)

for w in word:
  memo = 0
  for s in S:
    if w == s: memo += 1
  for t in T:
    if w == t: memo -= 1
  ans = max(ans, memo)
print(ans)