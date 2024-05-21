import sys
sys.setrecursionlimit(10**7)
N = int(input())
card = []
for _ in range(N):
  a, b = map(int, input().split())
  card.append([a, b])

used = [0]*N
pair = []
for i in range(N):
  for j in range(i+1, N):
    if card[i][0]==card[j][0] or card[i][1]==card[j][1]:
      pair.append((i, j))
memo = [-1]*(1<<20)
situ = 0
def dfs(turn):
  global situ
  if memo[situ]!=-1: return memo[situ]
  #turn = 1: takahashi
  s = [0, 0]
  for i, j in pair:
    if used[i] or used[j]: continue
    used[i] = 1
    used[j] = 1
    situ += (1<<i) + (1<<j)
    s[dfs(turn^1)] += 1
    situ -= (1<<i) + (1<<j)
    used[i] = 0
    used[j] = 0
  if sum(s)==0:
    ret = turn^1
  elif turn:
    if s[1]: ret = 1
    else: ret = 0
  else:
    if s[0]: ret = 0
    else: ret = 1
  memo[situ] = ret
  return ret

print("Takahashi" if dfs(1) else "Aoki")