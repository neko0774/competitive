inf = 10**18
N, M = map(int, input().split())
G = [[inf]*N for _ in range(N)]
for i in range(N): G[i][i] = 0
for _ in range(M):
    a,b,t = map(int, input().split())
    a -= 1
    b -= 1
    G[a][b] = t
    G[b][a] = t

for k in range(N):
    for i in range(N):
        for j in range(N):
            G[i][j] = min(G[i][j], G[i][k]+G[k][j])

ans = inf
for g in G:
    ans = min(ans, max(g))
print(ans)