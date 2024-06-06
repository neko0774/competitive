N, M = map(int, input().split())
A = [int(i) for i in input().split()]
for i in range(N):
  X = [int(i) for i in input().split()]
  for j in range(M):
    A[j] -= X[j]
print("Yes" if max(A)<=0 else "No")