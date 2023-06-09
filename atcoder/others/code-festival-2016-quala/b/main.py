N = int(input())
A = [int(i)-1 for i in input().split()]
cnt= 0
for n,a in enumerate(A):
    if A[a] == n: cnt += 1
print(cnt//2)