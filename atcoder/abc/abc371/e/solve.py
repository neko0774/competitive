N = int(input())
A = [int(i) for i in input().split()]
ans = 0
for i in range(N):
  for j in range(i, N):
    ans += len(set(A[i:j+1]))
print(ans)