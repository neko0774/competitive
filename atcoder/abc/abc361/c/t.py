N, K = map(int, input().split())
A = [int(i) for i in input().split()]

from collections import deque
A.sort()
V = []
for i in range(K):
  V.append(A.pop())
V.sort()
ans = 10**18
for i in range(K):
  ans = min(ans, A[-1] - A[i])
  A.append(V[i])
print(ans)