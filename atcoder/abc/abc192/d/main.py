X = input()
M = int(input())
if len(X)==1:
  print(1 if int(X)<=M else 0)
  exit()

ok = 0
for x in X:
  ok = max(ok, int(x))
d = ok
bad = 10**18+1

def good(n):
  #if X in n inshou <= M
  num = 0
  for x in X:
    num *= n
    num += int(x)
  return num <= M



while abs(ok-bad)>1:
  mid = (ok+bad)//2
  if good(mid):
    ok = mid
  else:
    bad = mid
print(ok-d)