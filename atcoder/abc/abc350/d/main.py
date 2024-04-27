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

N, M = map(int, input().split())
uf = UnionFind(N)
edges = []
for _ in range(M):
	u, v = map(int, input().split())
	u -= 1
	v -= 1
	uf.merge(u, v)
	edges.append([u, v])
G = uf.groups()
from collections import defaultdict
count = defaultdict(int)
for u, _ in edges:
	count[uf.find_root(u)] += 1
ans = 0
for s in G:
	ans += len(s)*(len(s)-1)//2-count[uf.find_root(s[0])]
print(ans)

