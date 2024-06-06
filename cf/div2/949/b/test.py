T = int(input())
for _ in range(T):
  A = [i for i in range(1000)]
  N, M = map(int, input().split())
  for i in range(M):
    B = A[:]
    for j in range(1, 999):
      A[j] |= A[j-1]|A[j+1]
  print(A[N])