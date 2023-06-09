class UnionFind:
	def __init__(self, N):
		self.root = list(range(N + 1))
		self.size = [1] * (N + 1)
		self.N = N
 
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
		if size[x] < size[y]:
			x, y = y, x
		root[y] = root[x]
		size[x] += size[y]
	
	def same(self, x, y):
		return self.find_root(x)==self.find_root(y)

	def groups(self):
		cnt = set()
		seen = [False]*self.N
		for i in range(self.N+1):
			x = self.find_root(i)
			if not x==i: cnt.add(x)
		return len(cnt)

	def groups(self):
		G = [[] for _ in range(self.N)]
		for i in range(self.N):
			G[self.find_root(i)].append(i)
		return [i for i in G if i]

def main():
    N, M = map(int, input().split())
    P = [int(i)-1 for i in input().split()]
    uf = UnionFind(N)

    ans = 0
    for _ in range(M):
        x,y = map(int, input().split())
        uf.merge(x-1, y-1)
    
    for g in uf.groups():
        g = set(g)
        comp = set()
        for gg in g:
            comp.add(P[gg])
        ans += len(g.intersection(comp))
    print(ans)
main()