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

Q, K = map(int, input().split())
query = []
V = []
for _ in range(Q):
  q, x = map(int, input().split())
  query.append([q, x])
  V.append(x)

conv = dict()
rev = dict()
V = sorted(list(set(V)))
print(V)
for i, v in enumerate(V):
  conv[v] = i
  rev[i] = v



N = len(conv)
uf = UnionFind(N)
from bisect import bisect_left as bl
for q, x in query:
  if q == 1:

  else:
    print(size[uf.find_root(conv[x])])