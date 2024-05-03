A = []
while True:
  N = int(input())
  A.append(N)
  if N==0: break
print(*A[::-1], sep='\n')