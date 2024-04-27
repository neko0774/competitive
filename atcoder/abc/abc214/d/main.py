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
		size[x] += size[y]
	
	def is_same(self, x, y):
		return self.find_root(x)==self.find_root(y)

	def group_size(self):
		return self.group_size

	def groups(self):
		G = [[] for _ in range(self.N)]
		for i in range(self.N):
			G[self.find_root(i)].append(i)
		return [i for i in G if i]

	def tree_size(self, x):
		return self.size[self.find_root(x)]

N = int(input())
G = [[] for _ in range(N)]
E = []

for i in range(N-1):
	u, v, w = map(int, input().split())
	u -= 1
	v -= 1
	G[u].append((v, w))
	G[v].append((u, w))
	E.append([w, u, v])

E.sort()
uf = UnionFind(N)
ans = 0
for w, u, v in E:
	ans += w*uf.tree_size(u)*uf.tree_size(v)
	uf.merge(u, v)
print(ans)