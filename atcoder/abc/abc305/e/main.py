class UnionFind:
	def __init__(self, N):
		self.root = list(range(N+1))
		self.size = [1]*(N+1)
		self.N = N
		self.group_size = N
 
	def find_root(self, x):
		root = self.root
		lis = []
		while root[x] != x:
			lis.append(x)
			x = root[x]
		for l in lis:
			root[l] = x
		return x
 
	def merge(self, x, y):
		root, size = self.root, self.size
		x = self.find_root(x)
		y = self.find_root(y)
		if x == y:
			return
		self.group_size -= 1
		if size[x] < size[y]:
			x, y = y, x
		root[y] = root[x]
		size[y] += size[x]
	
	def is_same(self, x, y):
		return self.find_root(x)==self.find_root(y)

	def group_size(self):
		return self.group_size

	def groups(self):
		G = [[] for _ in range(self.N)]
		for i in range(self.N):
			G[self.find_root(i)].append(i)
		return [i for i in G if i]

N, M, K = map(int, input().split())
G = [[] for _ in range(N)]
uf = UnionFind(N)

for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)
    uf.merge(a, b)


police = dict()
for _ in range(K):
    p, h = map(int, input().split())
    p -= 1
    police[p] = h

is_protected = set()
from collections import deque
q = deque([0])
change = dict()
dist = [[-1, -1]]*N
connection = 0
edges = []
for x in range(N):
    di = set()
    dist[x][0] = 0
    dist[x][1] = connection
    if dist[x]!=-1: continue
    q = deque([x])
    while q:
        x = q.popleft()
        di.add(x)
        if x in police:
            change[x] = dist[x]
        for nx in G[x]:
            if dist[nx][0]==-1:
                q.append(nx)
                dist[nx][0] = dist[x][0]+1
                dist[nx][1] = connection
    connection += 1
    edges.append(di)
print(dist)
max_dist = max(dist)
LR = [[] for _ in range(connection)]
for p,h in police.items():
    d = dist[p][-1]
    l = max(0, change[p]-h)
    r = min(change[p]+h, max_dist)
    LR[d].append([l, r])
ans = []
from bisect import bisect_left as bl
for i in range(connection):
    LR[i].sort()

    r = 0
    is_okay = set()
    lrlr = []
    l = 1000000
    r = -1
    for ll, rr in LR:
        if r<ll and not r==-1:
            lrlr.append(l, r)
        l = min(l, ll)
        r = max(r, rr)
    lrlr.append(l, r)
        
    for d in edges[i]:
        id = bl(lrlr, dist[d][0])
        if id%2==1: ans.append(d)

ans.sort()
print(*ans)