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
	
	def same(self, x, y):
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
cost = []
for _ in range(M):
	K, C = map(int, input().split())
	A = [int(i)-1 for i in input().split()]
	cost.append([C, A])
	x = A[0]
	for a in A[1:]:
		uf.merge(x, a)

if uf.group_size!=1:
	print(-1)
else:
	cost.sort()
	uf = UnionFind(N)
	ans = cost[0][0]*(len(cost[0][1])-1)
	p = cost[0][1][0]
	for x in cost[0][1]:
		uf.merge(x, p)
	for C, A in cost[1:]:
		p = A[0]
		for x in A[1:]:
			if not uf.same(x, p):
				ans += C
				uf.merge(x, p)
	print(ans)

