H, W, N = map(int, input().split())
X = [0] * N
Y = [0] * N
XY = []
for i in range(N):
	Y[i], X[i] = map(int, input().split())
	XY.append(X[i] + H * Y[i])
XY.sort()

LIS = [INF] * N
for i in range(N):
	