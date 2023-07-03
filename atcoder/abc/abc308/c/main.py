from functools import cmp_to_key
N = int(input())
ans = []
big = 10**9
inf = 10**18+1
def cmp(a, b):
  v = -a[0]*b[1]+a[1]*b[0]
  if v==0:
    if a[-1]>b[-1]: return 1
    else: return -1
  elif v>=0: return 1
  return -1
for i in range(N):
  A, B = map(int, input().split())
  ans.append([A, A+B, i+1])
ans = sorted(ans, key=cmp_to_key(cmp))
print(*[a[-1] for a in ans])