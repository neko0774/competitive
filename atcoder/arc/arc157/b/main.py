from collections import deque
N, K = map(int, input().split())
S = [i for i in input()]

l = ""
cnt = 0
XY = []
X = []
YY = deque()
for s in S:
    if s==l:
        cnt += 1
    else:
        if cnt>0:
            XY.append([l, cnt])
            if l=="X": XX.append(cnt)
            else: YY.append(cnt)
        cnt = 1
        l = s
XY.append([l, cnt]) 
if l=="X": XX.append(cnt)
else: YY.append(cnt)
print(XY)

if K<=sum(XX):
    X.sort()
else:
    ans = sum(XX)-len(XX)
    c= []
    if XY[0][0]=="Y":
        c.append(YY.popleft())
    if XY[-1][0]=="Y":
        c.append(YY.pop())
    for cc in sorted(c, reverse=True):
    YY.sort()
    K -= sum(XX)


