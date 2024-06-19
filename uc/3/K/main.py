from collections import defaultdict
ans = defaultdict(lambda : set())
while True:
  try:
    S = input()
  except EOFError:
    break
  S1, S2 = S.split(":")
  for s in S2.split(","):
    ans[s.lstrip()].add(S1)

items = []
for head, accos in ans.items():
  num = head.split("-")[1]
  B = []
  for item in accos:
    h = item.split("-")[1]
    B.append([int(h), item])
  B.sort()
  items.append([int(num), head, B])

items.sort()
for _, head, A in items:
  print(str(head)+":", end=" ")
  print(A[0][1], end="")
  for _, a in A[1:]:
    print(", "+str(a), end="")
  print()