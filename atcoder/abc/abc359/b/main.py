N = int(input())
A = [int(i) for i in input().split()]
ans = 0
for i in range(2*N-2):
  if A[i]==A[i+2]:
    ans += 1
print(ans)