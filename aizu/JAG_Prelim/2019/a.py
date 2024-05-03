while True:
  N, M = map(int, input().split())
  if N==0 and M ==0: exit()
  ans = 0
  A = [[] for _ in range(M)]
  for i in range(M):
    A[i] = [int(j) for j in input().split()]
  ans = 0
  for i in range(N):
    v = 0
    for j in range(M):
      v += A[j][i]
    ans = max(v, ans)
  print(ans)