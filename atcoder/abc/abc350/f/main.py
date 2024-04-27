S = ["("] + [i for i in input()] + [")"]
import sys
sys.setrecursionlimit(10**6)
from collections import defaultdict
blanket = defaultdict(int)
cnt = 0
for i, s in enumerate(S):
  if s=="(":
    last.append(i)
    cnt += 1
  elif s==")":
    blanket[last.pop()] = i+1
    cnt -= 1
  elif cnt%2==0:
    S[i] = S[i].swapcase()

def solve(l, r):
  ret = ""
  l+=1
  r-=1
  while r-l>0:
    if S[l]=="(":
      if depth%2==0:
        ret += solve(l, blanket[l])
      else:
        ret += solve(l, blanket[l])
      l = blanket[l]
    else:
      ret += S[l]
      l+=1
  return ret

print(solve(0, len(S)))