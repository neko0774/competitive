N, T = map(int, input().split())
A = [int(i)-1 for i in input().split()]

row = [0]*N
col = [0]*N
diag = [0, 0]
D1, D2 = set(), set()
b = 0
for i in range(N):
  D1.add(b)
  b += N+1
b = N-1
for i in range(N):
  D2.add(b)
  b += N-1
for i, a in enumerate(A):
  row[a//N] += 1
  col[a%N] += 1
  if a in D1:
    diag[0] += 1
  if a in D2:
    diag[1] += 1
  if row[a//N]==N or col[a%N]==N or diag[0] == N or diag[1]==N:
    print(i+1)
    exit()
print(-1)