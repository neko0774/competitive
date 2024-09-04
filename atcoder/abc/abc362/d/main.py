N, M = map(int, input().split())
A = [int(i) for i in input().split()]
G = [[] for _ in range(N)]
for i in range(M):
	u, v, b = map(int, input().split())
	u -= 1
	v -= 1
	G[u].append((v, b))
	G[v].append((u, b))

from heapq import heappush, heappop
inf = 10**18

def dijkstra(s, G, node=None):#s = start, n = number of the node
	if node==None: node = len(G)
	cost = [inf]*node
	hq = [(0, s)]
	seen = [False]*node
	cost[s] = A[s]
	while hq:
		d, v = heappop(hq)
		seen[v] = True
		if d > cost[v]: continue
		for to, weight in G[v]:
			if not seen[to] and cost[v] + weight + A[to] < cost[to]:
				cost[to] = cost[v] + weight + A[to]
				heappush(hq, (cost[to], to))
	return cost


ans = dijkstra(0, G)
print(*ans[1:])