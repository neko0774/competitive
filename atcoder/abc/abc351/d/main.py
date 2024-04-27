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

H, W = map(int, input().split())

S = [[i for i in input()] for _ in range(H)]


ans = 0
uf = UnionFind(H*W)
def ok(x, y):
  if S[y][x]=="#": return 0
  for dx, dy in [[0, 1], [1, 0], [-1, 0], [0, -1]]:
    if 0<=x+dx<W and 0<=y+dy<H and S[y+dy][x+dx]=='#':
      return 0
  return 1

check = [[ok(x, y) for x in range(W)] for y in range(H)]

def conv(x, y):
  return x+y*W

from collections import defaultdict
count = defaultdict(lambda : set())
for y in range(H):
  for x in range(W):
    if check[y][x]:
      for dx, dy in [[0, 1], [1, 0], [-1, 0], [0, -1]]:
        if 0<=x+dx<W and 0<=y+dy<H and check[y+dy][x+dx]:
          uf.merge(conv(x+dx, y+dy), conv(x, y))
        elif 0<=x+dx<W and 0<=y+dy<H and not S[y+dy][x+dx]=='#':
          count[conv(x, y)].add(conv(x+dx, y+dy))

ans = defaultdict(int)
check = defaultdict(lambda : set())
for nx, v in count.items():
  check[uf.find_root(nx)] |= v
for x in uf.groups():
  r = uf.find_root(x[0])
  ans[r] += len(x)+len(check[r])
print(max(ans.values()))