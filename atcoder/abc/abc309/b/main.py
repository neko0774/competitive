import copy
N = int(input())
A = [[i for i in input()] for _ in range(N)]
ans = copy.deepcopy(A)

for i in range(1, N-1):
  ans[0][i] = A[0][i-1]
  ans[-1][i] = A[-1][i+1]
  ans[i][0] = A[i+1][0]
  ans[i][-1] = A[i-1][-1]

ans[0][0] = A[1][0]
ans[0][-1] = A[0][-2]
ans[-1][0] = A[-1][1]
ans[-1][-1] = A[-2][-1]
for a in ans:
  print("".join(map(str, a)))