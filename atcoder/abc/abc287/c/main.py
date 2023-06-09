import sys
sys.setrecursionlimit(10**6)
N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    G[u].append(v)
    G[v].append(u)
seen = [0]*N
def dfs(x, par=-1):
    global seen
    seen[x] = 1
    if len(G[x])>2:
        print("No")
        exit()
    for nx in G[x]:
        if nx==par: continue
        if seen[nx]:
            print("No")
            exit()
        dfs(nx, x)
dfs(0)
if sum(seen)==N: print("Yes") 
else: print("No")