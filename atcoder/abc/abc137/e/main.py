from heapq import heappop, heappush
def main():
    N, M = map(int,input().split())
    H = [int(i) for i in input().split()]
    G = [[] for _ in range(N)]
    potential = 10**6
    for _ in range(M):
        u,v = map(int, input().split())
        u -= 1
        v -= 1
        G[u].append((v, potential+H[u]-H[y] if H[u]>H[y] else potential+2*(H[y]-H[u])))
        G[v].append((u, potential+H[u]-H[y] if H[u]>H[y] else potential+2*(H[y]-H[u])))

    def dijkstra(s, G):
        N = len(G)
        cost = [-1]*N
        dist = [-1]*N
        dist[s] = 0
        cost[s] = 0
        hq = [s]
        while hq:
            x = heappop(hq)
            for to, weight in G[x]:
                if dist[to]==-1 and cost[x]+weight>cost[to]:
                    cost[to] = cost[x]+weight
                    dist[to] = dist[x]+1
                    heappush(hq, to)
        for i in range(N):
            cost[i] -= potential*dist[i]
        return cost
    
    print(max(dijkstra(0, G)))
    


    



main()