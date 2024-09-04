N = int(input())
A = [int(i) for i in input().split()]

def factorization(x):
	i = 2
	ans = 0
	while i**2 <= x:
		e = 0
		while x%i == 0:
			e += 1
			x //= i
		if e>0:
			ans += e
		i += 1
	if x!=1: ans += 1
	return ans


count = [factorization(a) for a in A]

v = 0
for c in count:
  v ^= c
print("Bruno" if v == 0 else "Anna")