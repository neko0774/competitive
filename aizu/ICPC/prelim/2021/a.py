from collections import defaultdict
def solve():
  N = int(input())
  if N==0: exit()
  gold_count = defaultdict(int)
  count = defaultdict(int)

  for _ in range(N):
    y, s, m = input().split()
    y = int(y)
    if m=="Gold":
      gold_count[y]+=1
    count[y]+=1

  g = sorted([[cnt, y] for y, cnt in gold_count.items()], reverse=True)
  s = sorted([[cnt, y] for y, cnt in count.items()], reverse=True)
  gold = 10**6
  medal = 10**6
  for cnt, gg in g:
    if cnt==g[0][0]:
      gold = min(gold, gg)
  for cnt, mm in s:
    if cnt==s[0][0]:
      medal = min(medal, mm)
    else:
      break
  print(gold, medal)


while 1==1:
  solve()