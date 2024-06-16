class SegTree:
	def __init__(self, N, func, e=0):
		self._e = e
		self._func = func
		self._n = 1<<(N.bit_length())
		self.array = [e]*(self._n*2)

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


def solve():
  N, K = map(int, input().split())
  A = [int(i) for i in input().split()]
  S = [int(i) for i in input()]

  segL = SegTree(N, max, 0)
  segR = SegTree(N, min, N)
  seg =  SegTree(N, lambda x, y: x+y, 0)

  order = sorted([(A[i], 1-S[i], i) for i in range(N)], reverse=True)
  ans = 0
  for a, s, i in order:
    if 1-s==0:
      segL.update(i, i)
      segR.update(i, i)
    else:
      seg.update(i, 1)
      L = segL.fold(0, i)
      R = segR.fold(i, N)
      if seg.fold(L, R)>=K: ans = max(ans, a)

  print(ans)

solve()