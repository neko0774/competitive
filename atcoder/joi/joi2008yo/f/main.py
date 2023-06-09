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

N, K = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(K):
    s = input()
    if s[0]=="0":
        _, a, b = map(int, s.split())
        a -= 1
        b -= 1
        n = dijkstra(a, G)[b]
        print(-1 if n==inf else n)
    else:
        _, c,d,e = map(int, s.split())
        c -= 1
        d -= 1
        G[c].append((d, e))
        G[d].append((c, e))