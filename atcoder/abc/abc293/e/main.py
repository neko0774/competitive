A, X, M = map(int, input().split())

def calc(A, B):
  N = len(A)
  ans = [[0 for _ in range(N)] for _ in range(N)]
  for i in range(N):
    for j in range(N):
      for k in range(N):
        ans[j][i] += A[j][k]*B[k][i]
        ans[j][i] %= M
  return ans
vec = [[A%M, 1], [0, 1]]
ans = [[1, 0], [0, 1]]
while X:
  if X&1:
    ans = calc(ans, vec)
  vec = calc(vec, vec)
  X >>= 1
print(ans[0][1]) 
