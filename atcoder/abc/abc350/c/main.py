N = int(input())
A = [int(i)-1 for i in input().split()]

P = [-1]*N
for i in range(N):
  P[A[i]] = i

ans = []
for i in range(N-1):
  if A[i]!=i:
    x = P[i]
    y = P[A[i]]
    ans.append([x+1, y+1])
    P[i], P[A[i]] = P[A[i]], P[i]
    A[x], A[y] = A[y], A[x]
print(len(ans))
for i in ans:
  print(*sorted(i))