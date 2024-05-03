A, B, Q = map(int, input().split())
S = [int(input()) for _ in range(A)]
T = [int(input()) for _ in range(B)]
S.append(10**15)
S.append(10**15)
T.append(10**15)
T.append(10**15)
from bisect import bisect_left as bl
def solve():
	x = int(input())
	s = bl(S, x)
	if s!=0: s -= 1
	t = bl(T, x)
	if t!=0: t -= 1
	ans = 10**12
	for i in range(2):
		for j in range(2):
			ans = min(ans, abs(x-S[s+i])+abs(S[s+i]-T[t+j]), abs(x-T[t+j])+abs(S[s+i]-T[t+j]))
	print(ans)
for _ in range(Q):
	solve()