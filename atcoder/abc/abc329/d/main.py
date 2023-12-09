N, M = map(int, input().split())
A = [int(i) for i in input().split()]

class SegTree:
	#in the implementation of segment tree its 1-indexed 
	#but in use case, it is 0-indexed
	def __init__(self, N, e=0):
		self._e = e
		self._n = 1<<(N.bit_length())
		self.array = [[e, 0] for _ in range(self._n*2)]
		for i in range(self._n*2):
			self.array[i][1] = i

	def build(self, seq):
		for i, x in enumerate(seq):
			self.array[i+self._n][1] = i
		for i in range(1, self._n)[::-1]:
			if self.array[2*i][0]>=self.array[2*i+1][0]:
				self.array[i][0] = self.array[2*i][0]
				self.array[i][1] = self.array[2*i][1]
			else:
				self.array[i][0] = self.array[2*i+1][0]
				self.array[i][1] = self.array[2*i+1][1]



	def update(self, i, x):
		i += self._n
		self.array[i][0] += x
		while i>1:
			i //= 2
			if self.array[2*i][0]>=self.array[2*i+1][0]:
				self.array[i][0] = self.array[2*i][0]
				self.array[i][1] = self.array[2*i][1]
			else:
				self.array[i][0] = self.array[2*i+1][0]
				self.array[i][1] = self.array[2*i+1][1]

	def all_fold(self):
		return self.array[1][1]

SGT = SegTree(N+5)
SGT.build([0]*(N+1))
for a in A:
	SGT.update(a, 1)
	print(SGT.all_fold())