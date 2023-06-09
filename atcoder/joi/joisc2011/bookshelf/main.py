import sys
input = sys.stdin.readline

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



def func(x, y):
    return max(x, y)

N = int(input())
A = [int(input())*2 for _ in range(N)]
shelf = [int(input())-1 for _ in range(N)]
st = SegTree(N, func)
ma = 0
for b in shelf:
	w = st.fold(0, b)+A[b]
	st.update(b, w)
	ma = max(ma, w)
print(sum(A)-ma)