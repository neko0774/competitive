A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
def judge(A, B):
  Axmi, Axma = min(A[0], A[3]), max(A[0], A[3])
  Bxmi, Bxma = min(B[0], B[3]), max(B[0], B[3])
  Aymi, Ayma = min(A[1], A[4]), max(A[1], A[4])
  Bymi, Byma = min(B[1], B[4]), max(B[1], B[4])
  Azmi, Azma = min(A[2], A[5]), max(A[2], A[5])
  Bzmi, Bzma = min(B[2], B[5]), max(B[2], B[5])
  if ((A[0] < B[0] < A[3] or A[0] < B[3] < A[3] or Axmi == Bxmi or Axma == Bxma) and (A[1] < B[1] < A[4] or A[1] < B[4] < A[4] or Aymi == Bymi or Ayma == Byma) and (A[2] < B[2] < A[5] or A[2] < B[5] < A[5] or Azmi == Bzmi or Azma == Bzma)):return 1
  


if judge(A, B) or judge(B, A) or A == B:
  print("Yes")
else:
  print("No")