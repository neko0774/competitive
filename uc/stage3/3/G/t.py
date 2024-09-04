N = 5
import itertools as it

def greedy(S):
  N = len(S)
  rev = [-1]*(N+1)
  for i in range(N):
    rev[S[i]] = i
  used = set()
  ans = []
  for s in S:
    if s not in used and rev[s] not in used:
      if s == rev[s]:
        ans.append(s)
        used.add(s)
      else:
        ans.append(s)
        ans.append(rev[s] + 1)
        used.add(s)
        used.add(rev[s])
  for i in range(1, N+1):
    if i not in used: ans.append(i)
  print(*ans)


def solve():
  for iter in it.permutations(range(1, N+1)):
    greedy(iter)

greedy([1, 2, 3, 4])