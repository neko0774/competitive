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
		return [set(i) for i in G if i]


N, M = map(int, input().split())
uf = UnionFind(N)
for _ in range(M):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    uf.merge(u, v)
K = int(input())
badpairs = set()
for _ in range(K):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    x = uf.find_root(x)
    y = uf.find_root(y)
    if x<y:
        x, y = y, x
    badpairs.add((x, y))
Q = int(input())
for _ in range(Q):
    p, q = map(int, input().split())
    p -= 1
    q -= 1
    x = uf.find_root(p)
    y = uf.find_root(q)
    if x<y:
        x, y = y, x
    if (x, y) in badpairs:
        print("No")
    else:
        print("Yes")