H, W = map(int, input().split())
S = [[i for i in input()] for _ in range(H)]
T = [[i for i in input()] for _ in range(H)]


check = []
from collections import defaultdict
count = defaultdict(int)
for x in range(W):
  memo1 = []
  memo2 = []
  for y in range(H):
    memo1.append(S[y][x])
    memo2.append(T[y][x])
  check.append("".join(memo1))
  count["".join(memo2)] += 1
for s in check:
  if count[s]<1:
    print("No")
    exit()
  count[s] -= 1
print("Yes")