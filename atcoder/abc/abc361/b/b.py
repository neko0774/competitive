A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
Axmi, Axma = min(A[0], A[3]), max(A[0], A[3])
Bxmi, Bxma = min(B[0], B[3]), max(B[0], B[3])
Aymi, Ayma = min(A[1], A[4]), max(A[1], A[4])
Bymi, Byma = min(B[1], B[4]), max(B[1], B[4])
Azmi, Azma = min(A[2], A[5]), max(A[2], A[5])
Bzmi, Bzma = min(B[2], B[5]), max(B[2], B[5])

X = Axmi < Bxmi and Axma > Bxmi
Y = Aymi < Bymi and Ayma > Bymi
Z = Azmi < Bzmi and Azma > Bzmi
if X and Y and Z:
  print("Yes")
else:
  print("No")