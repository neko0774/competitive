N, M = map(int, input().split())
G = [[] for _ in range(N)]

class UnionFind:
	def __init__(self, N):
		self.root = list(range(N + 1))
		self.size = [1] * (N + 1)
		self.N = N
 
	def find_root(self, x):
		root = self.root
		while root[x] != x:
			root[x] = root[root[x]]
			x = root[x]
		return x
 
	def merge(self, x, y):
		root, size = self.root, self.size
		x = self.find_root(x)
		y = self.find_root(y)
		if x == y:
			return
		if size[x] < size[y]:
			x, y = y, x
		root[y] = root[x]
		size[x] += size[y]
	
	def same(self, x, y):
		return self.find_root(x)==self.find_root(y)

	def group_size(self):
		cnt = set()
		seen = [False]*self.N
		for i in range(self.N+1):
			x = self.find_root(i)
			if not x==i: cnt.add(x)
		return len(cnt)

	def groups(self):
		G = [[] for _ in range(self.N)]
		for i in range(self.N):
			G[self.find_root(i)].append(i)
		return [i for i in G if i]

uf = UnionFind(N)
edges = []
ans = 0
for _ in range(M):
    A,B,C = map(int, input().split())
    edges.append([C, A-1, B-1])
edges.sort()
for c,a,b in edges:
    if c<=0:
        uf.merge(a, b)
    elif uf.same(a, b):
        ans += c
    else:
        uf.merge(a, b)
print(ans)