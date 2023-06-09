from heapq import heappush, heappop
inf = 10**12
def dijkstra(s, G, node=None):#s = start, n = number of the node
	if node==None: node = len(G)
	cost = [inf]*node
	hq = [(0, s)]
	seen = [False]*node
	cost[s] = 0
	while hq:
		v = heappop(hq)[1]
		seen[v] = True
		for to, weight in G[v]:
			if not seen[to] and cost[v] + weight < cost[to]:
				cost[to] = cost[v] + weight
				heappush(hq, (cost[to], to))
	return cost

N, M, T = map(int, input().split())
A = [int(i) for i in input().split()]
G = [[] for _ in range(N)]
rG = [[] for _ in range(N)]
for _ in range(M):
    a,b,c = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append((b, c))
    rG[b].append((a, c))

dist = dijkstra(0, G)
back = dijkstra(0, rG)
ans = 0
for n in range(N):
    ans = max(ans, A[n]*(T-dist[n]-back[n]))
print(ans)