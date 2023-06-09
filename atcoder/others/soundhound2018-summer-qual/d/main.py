N, M, S, T = map(int, input().split())
G = [[] for _ in range(N)]
S -= 1
T -= 1
for _ in range(M):
    u,v,a,b = map(int, input().split())
    u -= 1
    v -= 1
    G[u].append((v,a,b))
    G[v].append((u,a,b))

from heapq import heappush, heappop
inf = 1<<60
def dijkstra(x, index):
    q = [(0, x)]
    dist = [inf]*N
    dist[x] = 0
    seen = [0]*N
    while q:
        x = heappop(q)[1]
        seen[x] = 1
        for n in G[x]:
            nx,w = n[0], n[index]
            if not seen[nx] and dist[nx]>dist[x]+w:
                dist[nx] = dist[x]+w
                heappush(q, (dist[nx], nx))
    return dist

yen = dijkstra(S, 1)
snook = dijkstra(T, 2)

ans = [0]*N
ans[-1] = 10**15-(yen[-1]+snook[-1])
for n in range(N-1)[::-1]:
    ans[n] = max(ans[n+1], 10**15-(yen[n]+snook[n]))
print(*ans, sep="\n")