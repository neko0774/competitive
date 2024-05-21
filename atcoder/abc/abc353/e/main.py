N = int(input())
S = [i for i in input().split()]
size = 10**5
SS = [len(s) for s in S]
SS.sort()
if N==1:
  print(0)
  exit()
size = SS[-2]

def f(S1, S2):
  for i in range(min(len(S1), len(S2))):
    if S1[i]!=S2[i]:
      return i
  return i+1

if N<=100:
  ans = 0
  for i in range(N):
    for j in range(i+1, N):
      ans += f(S[i], S[j])
  print(ans)
  exit()

from collections import defaultdict
count = defaultdict(int)
for SS in S:
  memo = []
  for n, s in enumerate(SS):
    if n>size:
      break
    memo.append(s)
    count["".join(memo)] += 1

ans = 0
for SS in S:
  memo = []
  for n, s in enumerate(SS):
    if n>size:
      break
    memo.append(s)
    count["".join(memo)] -= 1
    ans += count["".join(memo)]
print(ans)