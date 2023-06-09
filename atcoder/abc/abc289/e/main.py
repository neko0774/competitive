from collections import deque
def solve():
    N, M = map(int, input().split())
    C = [int(i) for i in input().split()]
    G = [[] for _ in range(N)]
    for _ in range(M):
        u,v = map(int, input().split())
        u -= 1
        v -= 1
        G[u].append(v)
        G[v].append(u)
    
    q = deque([[0, N-1]])
    dist = [[-1]*N for _ in range(N)]
    dist[-1][0] = 0
    while q:
        t, a = q.popleft()
        for nt in G[t]:
            for na in G[a]:
                if dist[na][nt]==-1 and C[na]!=C[nt]:
                    dist[na][nt] = dist[a][t]+1
                    q.append([nt, na])
    print(dist[0][-1])

T = int(input())
for _ in range(T):
    solve()
