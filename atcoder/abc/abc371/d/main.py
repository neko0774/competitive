class SegTree:
	#in the implementation of segment tree its 1-indexed 
	#but in use case, it is 0-indexed
	def __init__(self, N, func, e=0):
		self._e = e
		self._func = func
		self._n = 1<<(N.bit_length())
		self.array = [e]*(self._n*2)

	def build(self, seq):
		for i, x in enumerate(seq):
			self.array[i+self._n] = x
		for i in range(1, self._n)[::-1]:
			self.array[i] = self._func(self.array[2*i], self.array[2*i+1])
	
	def update(self, i, x):
		i += self._n
		self.array[i] = x
		while i>1:
			i //= 2
			self.array[i] = self._func(self.array[2*i], self.array[2*i+1])
	
	def fold(self, l, r):
		l += self._n
		r += self._n
		vl = self._e
		vr = self._e
		while r-l>0:
			if r&1:
				r -= 1
				vr = self._func(vr, self.array[r])
			if l&1:
				vl = self._func(vl, self.array[l])
				l += 1
			r //= 2
			l //= 2
		return self._func(vl, vr)

	def all_fold(self):
		return self.array[1]
	
	def get(self, i):
		return self.array[i+self._n]

N = int(input())
X = [int(i) for i in input().split()]
P = [int(i) for i in input().split()]

comp = set(X)

Q = int(input())
query = []
for _ in range(Q):
	l, r = map(int, input().split())
	query.append([l, r])
	comp.add(l)
	comp.add(r)

conv = {j:i for i, j in enumerate(sorted(list(comp)))}

seg = SegTree(len(conv), lambda x, y: x + y, 0)
for x, p in zip(X, P):
	seg.update(conv[x], p)

ans = []
for l, r in query:
	ans.append(seg.fold(conv[l], conv[r] + 1))
print(*ans, sep = '\n')