A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
C = [int(i) for i in input().split()]
V1 = [A[0] - B[0], A[1] - B[1]]
V2 = [B[0] - C[0], B[1] - C[1]]
V3 = [C[0] - A[0], C[1] - A[1]]
def ok(A, B):
  return A[0] * B[0] + A[1] * B[1] == 0

if ok(V1, V2) or ok(V2, V3) or ok(V3, V1):
  print("Yes")
else:
  print("No")