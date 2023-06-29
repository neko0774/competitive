N = int(input())
G = [[] for _ in range(N)]
for _ in range(N-1):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    G[u].append((v, w))
    G[v].append((u, w))

dist = [0]*N
def dfs(par, x):
    for nx,w in G[x]:
        if x==par: continue
        dist[nx] = dist[x]^dist[nx]
        dfs(x, nx)
dfs(-1, 0)


count = [0]*61
for i in range(61):
    for n in range(N):
        if dist[n]>>i&1: count[i] += 1

print(dist)
print(count)