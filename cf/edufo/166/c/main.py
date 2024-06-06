T = int(input())
for _ in range(T):
  N, M = map(int, input().split())
  S = N+M+1
  A = [int(i) for i in input().split()]
  B = [int(i) for i in input().split()]
  ans = []
  progs = set()
  tests = set()
  p = 0
  t = 0
  inf = 10**18
  next_p = [[inf, inf] for _ in range(N+M+1)]
  for i in range(N+M):
    if len(progs)==N and A[i]>B[i] and i>0:
      next_p[i-1][0] = i
    if len(tests)==N and A[i]<B[i] and i>0:
      next_p[i-1][1] = i

    if (A[i]>B[i] or len(tests)>=M) and N>len(progs):
      progs.add(i)
      p += A[i]
    else:
      tests.add(i)
      t += B[i]
  print(next_p)
  for i in range(1, N+M+1)[::-1]:
    next_p[i-1][0] = min(next_p[i-1][0], next_p[i][0])
    next_p[i-1][1] = min(next_p[i-1][1], next_p[i][1])
  print(p, t)
  print(progs, tests)
  print(next_p)
  for i in range(N+M):
    if i in progs:
      if next_p[i][0]!=inf:
        nx = next_p[i][0]
        ans.append(p+t-A[i]+A[nx]-B[nx]+B[-1])
      else:
        ans.append(p+t+A[-1]-A[i])
    else:
      if next_p[i][1]!=inf:
        nx = next_p[i][1]
        ans.append(p+t-B[i]+B[nx]-A[nx]+A[-1])
      else:
        ans.append(p+t+B[-1]-B[i])
  ans.append(p+t)
  print(*ans)
