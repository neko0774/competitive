N, M = map(int, input().split())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]

C = []
for a in A:
  C.append([a, 1])
for b in B:
  C.append([b, 2])
C.sort()
for i in range(N+M-1):
  if C[i][1]==C[i+1][1]==1:
    print("Yes")
    exit()
print("No")