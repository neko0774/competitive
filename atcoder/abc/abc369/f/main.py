H, W, N = map(int, input().split())
X = [0] * N
Y = [0] * N
XY = []
for i in range(N):
	Y[i], X[i] = map(int, input().split())
	XY.append((X[i], Y[i]))
XY.sort()
from bisect import bisect_left as bl

INF = 10**12
LIS = [INF] * N
for i in range(N):
	idx = bl(LIS, XY[i])
	LIS[idx] = XY[i]

print(LIS)