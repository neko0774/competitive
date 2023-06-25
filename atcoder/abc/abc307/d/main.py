N = int(input())
S = [i for i in input()]
import sys
sys.setrecursionlimit(10**8)
#the correct () can be erased
x = 0
remove = []
def dfs():
    global x
    sx = x
    x += 1
    while x<N:
        if S[x]=="(":
            dfs()
        elif S[x]==")":
            remove.append([sx, x])
            return
        x += 1
while x<N:
    if S[x]=="(":
        dfs()
    x += 1
remove.sort()
ans = ""
remove.append([N, N])
ly = -1
lx = 0
for x, y in remove:
    if lx<x and ly<y: ans += "".join(S[lx:x])
    ly = max(y, ly)
    lx = max(lx, y+1)
print(ans)