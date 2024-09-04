N = int(input())
S = [i for i in input()]
T = [i for i in input()]
S.append('.')
S.append('.')
T.append('.')
T.append('.')
def count(S):
  ret = 0
  for s in S:
    if s == 'W': ret += 1
  return ret
if count(S) != count(T):
  print(-1)
  exit()

import sys
sys.setrecursionlimit(10**7)
ans = 10**12
cnt = 0
def dfs():
  #print(S, T)
  global cnt, ans
  print(S, T)
  for x in range(N):
    if S[x]!=T[x]:
      for y in range(x+2, N+2):
        S[x], S[y] = S[y], S[x]
        S[y+1], S[x+1] = S[x + 1], S[x+1]
        cnt += 1
        dfs()
        S[x], S[y] = S[y], S[x]
        S[y+1], S[x+1] = S[x + 1], S[x+1]
        cnt -= 1
  if S == T: ans = min(ans, cnt)
dfs()
print(ans if ans != 10**12 else -1)