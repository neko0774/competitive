N, M = map(int, input().split())
S = input()
T = input()
strings = []
l = ""
for t in T:
  l += t
  strings.append(l)

stringsb = []
for i in range(M):
  stringsb.append(T[i:])

sss = set(strings)|set(stringsb)
stringsb = sss
print(stringsb)
#from back
back = [N]
clearb = set()
clearb.add(N)
finishb = set()
while back:
  nb = []
  for i in back:
    for st in stringsb:
      buffer = len(st)
      print(st, buffer, i, buffer)
      if i-buffer>=0 and S[i-buffer:i] == st:
        if i-buffer not in clearb:
          nb.append(i-buffer)
          clearb.add(i-buffer)
        if st==T[:buffer]:
          finishb.add(i-buffer)
  back = nb
print(clearb)
print(finishb)