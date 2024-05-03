N = int(input())
A = [[i for i in input()] for _ in range(N)]
B = [[i for i in input()] for _ in range(N)]

for i in range(N):
  for j in range(N):
    if A[i][j] != B[i][j]:
      print(i+1, j+1)
      exit()