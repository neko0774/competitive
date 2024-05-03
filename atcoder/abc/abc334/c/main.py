N, K = map(int, input().split())
A = [int(i) for i in input().split()]

from collections import Counter
C = Counter([i for i in range(1, N+1)]*2)
for a in A:
  C[a]-=1
socks = []
for v, c in C.items():
  for _ in range(c):
    socks.append(v)
socks.sort()


N = len(socks)
if K%2==0:
  ans = 0
  for i in range(0, N, 2):
    ans += socks[i+1]-socks[i]
else:
  left = [0]*(N//2+1)
  right = [0]*(N//2+1)
  ans = 1e8
  for i in range(N//2):
    left[i+1] = socks[2*i+1]-socks[2*i]+left[i]
    right[i+1] = abs(socks[-2*i-2]-socks[-2*i-1])+right[i]
  for i in range(N//2+1):
    ans = min(ans, left[i]+right[-i-1])
print(ans) 