N = int(input())
S = sorted([i for i in input()], reverse=True)
S = "".join(S)
zcnt = 0
while S[-1]=='0':
  zcnt += 1
  S.rstrip()
ans = 0
for i in range(1, 1e7+1):
  c = sorted(str(i*i), reverse=True)
  zz = 0
  while c[-1]=='0':
    c.rstrip()
    zz += 1
  
  if zcnt>=zz and c==S:
    ans += 1
print(ans)