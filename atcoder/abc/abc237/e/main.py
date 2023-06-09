from heapq import heappop, heappush
from collections import deque
inf = 10*12
def main():
    N, M = map(int,input().split())
    H = [int(i) for i in input().split()]
    G = [[] for _ in range(N)]
    for _ in range(M):
        u,v = map(int, input().split())
        u -= 1
        v -= 1
        G[u].append((v, max(0, 2*(H[u]-H[v]))))
        G[v].append((u, max(0, 2*(H[u]-H[v]))))
    print(G)
    
    def dijkstra(s, G, node=None):#s = start, n = number of the node
	    if node==None: node = len(G)
	    cost = [inf]*node
	    hq = [s]
	    seen = [False]*node
	    cost[s] = 0
	    while hq:
		    v = heappop(hq)
		    seen[v] = True
		    for to, weight in G[v]:
			    if not seen[to] and cost[v] + weight < cost[to]:
				    cost[to] = cost[v] + weight
				    heappush(hq, to)
	    return cost
    
    dist = dijkstra(0, G)
    q = deque([0])
    seen = [False]*N
    seen[0] = True
    while q:
        x=q.popleft()
        for nx, _ in G[x]:
            dist[nx] = max(dist[x]+H[x]-H[nx], dist[nx])
            if not seen[nx]:
                seen[nx] = True
                q.append(nx)
    print(max(dist+[0
main()