A, B = input().split()
A = int(A)
B = int(B.replace(".", ""))
ans = A*B//100
print(ans)