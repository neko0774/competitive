N, M = map(int, input().split())
S = input()
T = input()
strings = []
l = ""
for t in T:
  l += t
  strings.append(l)

#from front 
start = [0]
clear = set()
clear.add(0)
finish = set()
while start:
  ns = []
  for i in start:
    for buffer, st in enumerate(strings):
      buffer += 1
      if i+buffer<N and S[i:i+buffer] == st:
        if i+buffer not in clear:
          ns.append(i+buffer)
          clear.add(i+buffer)
        if buffer == M:
          finish.add(i+buffer)
  start = ns

stringsb = []

for i in range(M):
  stringsb.append(T[i:])
#from back
back = [N]
clearb = set()
clearb.add(N)
finishb = set()
while back:
  nb = []
  for i in back:
    for buffer, st in enumerate(stringsb[::-1]):
      buffer += 1
      if i-buffer>=0 and S[i-buffer:i] == st:
        if i-buffer not in clearb:
          nb.append(i-buffer)
          clearb.add(i-buffer)
        if buffer==M:
          finishb.add(i-buffer)
  back = nb


#front is )
#back is [
front = sorted(list(clear))
back = sorted(list(clearb))


fok = front[-min(5, len(front)):]
bok = back[:min(5, len(back))]
#print(fok, bok)
#print(finish, finishb)

TT = set()
for i in range(M):
  for j in range(i+1, M+1):
    TT.add(T[i:j])

for f in fok:
  for b in bok:
    l = b-f
    #print(f, b, l, T[f:b])
    if (l<=0 and (b in finishb or f in finish)) or (S[f:b] in TT and b in finishb and f in finish):
      print("Yes")
      exit()
print("No")