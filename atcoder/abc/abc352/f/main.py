class PotentialUnionFind:
	def __init__(self, N):
		self.root = list(range(N+1))
		self.size = [1]*(N+1)
		self.N = N
		self.weight = [0]*(N+1)
		self.group_size = N
 
	def find_root(self, x):
		if self.root[x]==x:
			return x
		y = self.find_root(self.root[x])
		self.weight[x] += self.weight[self.root[x]]
		self.root[x] = y
		return y
 
	def merge(self, x, y, w):
		root, size, weight = self.root, self.size, self.weight
		rx = self.find_root(x)
		ry = self.find_root(y)
		if x == y:
			return
		self.group_size -= 1
		if size[rx] < size[ry]:
			root[ry] = ry
			weight[rx] = w - weight[x] + weight[y]
		else:
			root[ry] = rx
			weight[ry] = -w - weight[y] + weight[x]
			if size[rx] == size[ry]:
				size[rx] += 1
	
	def is_same(self, x, y):
		return self.find_root(x)==self.find_root(y)

	def group_size(self):
		return self.group_size

	def diff(self, x, y):
		return self.weight[x] - self.weight[y]

	def groups(self):
		G = [[] for _ in range(self.N)]
		for i in range(self.N):
			G[self.find_root(i)].append(i)
		return [i for i in G if i]
import sys
sys.setrecursionlimit(10**6)

N, M = map(int, input().split())
G = [[] for _ in range(N)]
uf = PotentialUnionFind(N)
for _ in range(M):
	A, B, C = map(int, input().split())
	A -= 1
	B -= 1
	G[B].append([A, C])
	G[A].append([B, -C])
	uf.merge(A, B, C)

pos_rank = [set() for _ in range(N)]

ary = []
for g in uf.groups():
	GG = []
	for x in g:
		GG.append([uf.weight[x], x])
	GG.sort(reverse=True)
	ary.append([x for _, x in GG])	

def check(cur, pos, i):
	if i>=len(ary):
		return
	g = ary[i]
	print(cur, i, pos, g)
	if min(pos)>=0:
		for n, g in enuemrate(pos):
			pos_rank[n].add(g)
		return
	pos[cur] = g[0]
	ok = 1
	print(pos)
	for x in g[1:]:
		print(x, cur+uf.diff(g[0], x))
		if not 0<=cur+uf.diff(g[0], x)<len(pos):
			ok = 0
			break
		pos[cur+uf.diff(g[0], x)] = x
	print(pos)
	if ok:
		for i in range(cur+1, len(pos)):
			if pos[i]==-1:
				check(i, pos, i+1)
	pos[cur] = -1
	for x in g[1:]:
		if not 0<=cur+uf.diff(g[0], x)<len(pos):
			break
		pos[cur+uf.diff(g[0], x)] = -1
	return


for i in range(N):
	rank = [-1]*N
	check(i, rank, 0)
print(pos_rank)