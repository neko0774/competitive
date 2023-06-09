class BIT:
  #1th index
	def __init__(self, N, A=None):
		self.size = N
		self.data = [0]*(N+1)
		if A:
			for i in range(N):
				self.add(i+1, A[i])

	def rsum(self, l, r):
		return self.sum(l)-self.sum(r)

	def sum(self, r):
		s = 0
		while r>0:
			s += self.data[r]
			r -= r&-r
		return s
  
	def add(self, i, x):
		while i<=self.size:
			self.data[i] += x
			i += i&-i
	  

N = int(input())
S = [i for i in input()]


count = [BIT(N) for _ in range(27)]
for n,s in enumerate(S):
	count[ord(s)-ord("a")].add(n+1, 1)

Q = int(input())
for _ in range(Q):
	q, x, y = input().split()
	x = int(x)-1
	if q=="1":
		count[ord(S[x])-ord("a")].add(x, -1)
		count[ord(y)-ord("a")].add(x, 1)
	else:
		y = int(y)-1
		ans = 0
		for i in range(27):	
			ans += max(1, count[i].rsum(x-1, y))
		print(ans)