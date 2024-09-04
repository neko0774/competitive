N, K = map(int, input().split())
A = [int(i) for i in input().split()]

A.sort()
ans = 10**18
for i in range(K + 1):
  ans = min(ans, A[-K + i - 1] - A[i])
print(ans)