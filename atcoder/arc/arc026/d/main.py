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


N, M = map(int, input().split())
G = []
for _ in range(M):
    a,b,c,t = map(int, input().split())
    G.append([a,b,c,t])
def check(x):
    uf = UnionFind(N)
    ret = 0
    GG = sorted([[c-t*x, a,b] for a,b,c,t in G])
    for s, a, b in GG:
        if uf.is_same(a, b):
            if s<=0:
                ret += s
        else:
            ret += s
            uf.merge(a, b)
    return ret<0
    


ok = 10**6
ng = -1
for _ in range(100):
    m = (ok+ng)/2
    if check(m): ok = m
    else: ng = m
print(ok)