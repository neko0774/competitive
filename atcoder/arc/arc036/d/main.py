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

N, Q = map(int, input().split())
uf = UnionFind(N)
G = [set() for _ in range(N)]
for _ in range(Q):
    w, x, y, z = map(int, input().split())
    x -= 1
    y -= 1
    if w==1:
        z %= 2
        if z==0:
            uf.merge(x, y)
            s = uf.find_root(x)
            G[s] |= G[y]
            G[s] |= G[x]
        else:
            x = uf.find_root(x)
            y = uf.find_root(y)
            G[x].add(y) 
            G[y].add(x)
    else:
        print("YES" if uf.is_same(x, y) else "NO")
    #print(uf.groups(), G, conv)