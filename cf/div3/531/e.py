mod = 998244353
 
N = int(input())
A = [int(i) for i in input().split()]

cnt = 0
place = dict()
for n,a in enumerate(A):
	if a in place:
		place[a].append(n)
	else:
		place[a] = [n]
seen = set()
n = 1
for i in range(N):
	if n<=i:
		cnt += 1
		seen = set([A[i]])
		n = place[A[i]][-1]+1
	else:
		if not A[i] in seen:
			n = max(n, place[A[i]][-1]+1)
			seen.add(A[i])
	#print(seen, n)
if seen: cnt += 1
print(pow(2, cnt-1, mod))