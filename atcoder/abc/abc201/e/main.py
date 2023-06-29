N = int(input())
G = [[] for _ in range(N)]
for _ in range(N-1):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    G[u].append((v, w))
    G[v].append((u, w))
import sys
sys.setrecursionlimit(10**7)

dist = [0]*N
def dfs(par, x):
    for nx,w in G[x]:
        if nx==par: continue
        dist[nx] = dist[x]^w
        dfs(x, nx)
dfs(-1, 0)


count = [0]*60
for i in range(60):
    for n in range(N):
        if dist[n]>>i&1: count[i] += 1
ans = 0
mod = 10**9+7
for i in range(60):
    z, o = 0, 0
    for n in range(N):
        if dist[n]>>i&1: o += 1
        else: z += 1
    ans += (1<<i)*o*z
    ans %= mod
print(ans)