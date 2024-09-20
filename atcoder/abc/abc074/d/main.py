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


from heapq import heappush, heappop
def dist(s, g):
  N = len(G)
  q = [(0, s)]
  seen = [0] * N
  while q:
    _, x = heappop(q)

N = int(input())
G = [[] for _ in range(N)]
edges = []
uf = UnionFind(N)
for i in range(N):
	A = [int(i) for i in input().split()]
	for j, a in enumerate(A):
		edges.append((a, i, j))
edges.sort()

for c, i, j in edges:
  if uf.is_same(i, j):
    if dist(i, j) < c:
      print(-1)
      exit()
  else:
    uf.merge(i, j)
    G[i].append((c, j))
    G[j].append((c, i))