N, M = map(int, input().split())
X = [int(i) for i in input().split()]
X.sort()
ans = N*(N+1)//2
for x in X:
  xx = x
  while xx<N:
    