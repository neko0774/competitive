class UnionFind:
	def __init__(self, N):
		self.root = list(range(N + 1))
		self.size = [1] * (N + 1)
		self.N = N
		self.group_size = N
 
	def find_root(self, x):
		root = self.root
		while root[x] != x:
			root[x] = root[root[x]]
			x = root[x]
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
from collections import defaultdict
N, K, L = map(int, input().split())
train = UnionFind(N)
road = UnionFind(N)
for _ in range(K):
    p, q = map(int, input().split())
    p -= 1
    q -= 1
    road.merge(p, q)
for _ in range(L):
    p, q = map(int, input().split())
    p -= 1
    q -= 1
    train.merge(p, q)

count = defaultdict(int)
ans = [0]*N
for i in range(N):
    count[(road.find_root(i), train.find_root(i))] += 1

for i in range(N):
    ans[i] = count[(road.find_root(i), train.find_root(i))]
print(*ans)