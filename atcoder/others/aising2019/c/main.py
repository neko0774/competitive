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


H, W = map(int, input().split())
S = []
for _ in range(H):
    S += [i for i in input()]
dxy = [(0, 1), (1,0), (-1, 0), (0, -1)]

uf = UnionFind(H*W)
for y in range(H):
    for x in range(W):
        for dx, dy in dxy:
            nx, ny = x+dx, y+dy
            if 0<=nx<W and 0<=ny<H and S[ny*W+nx]!=S[y*W+x]:
                uf.merge(x+y*W, nx+ny*W)

ans = 0
for gg in uf.groups():
    cnt = {"#":0, ".":0}
    for g in gg:
        cnt[S[g]] += 1
    ans += cnt["."]*cnt["#"]
print(ans)




