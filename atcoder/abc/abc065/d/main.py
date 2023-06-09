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
N = int(input())
c1 = []
c2 = []
for i in range(N):
    x, y = map(int, input().split())
    c1.append([x, y, i])
    c2.append([y, x, i])
uf = UnionFind(N)
c1.sort()
c2.sort()
def add(city):
    ret = []
    lx = city[0][-1]
    lc = city[0][0]
    for c, _, x in city[1:]:
        ret.append([abs(c-lc), lx, x])
        lx = x
        lc = c
    return ret

e = add(c1)+add(c2)
e.sort()

ans = 0
for c,u,v in e:
    if not uf.is_same(u, v):
        ans += c
        uf.merge(u, v)
print(ans)