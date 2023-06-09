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
uf = UnionFind(N)
count = dict()
for _ in range(M):
    a,b,c,d = input().split()
    a = int(a)-1
    c = int(c)-1
    uf.merge(a, c)
    if a in count:
        if b=="R": count[a][0] += 1
        else: count[a][1] += 1
    else:
        if b=="R": count[a] = [1, 0]
        else: count[a] = [0, 1]
    if c in count:
        if d=="R": count[c][0] += 1
        else: count[c][1] += 1
    else:
        if d=="R": count[c] = [1, 0]
        else: count[c] = [0, 1]
    
X = 0
Y = 0
for g in uf.groups():
    is_cycle = True
    for gg in g:
        if not gg in count or not count[gg] == [1, 1]:
            is_cycle = False
            Y += 1
            break
    if is_cycle: X += 1

print(X, Y)