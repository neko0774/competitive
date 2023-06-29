N = int(input())
A = [int(i) for i in input().split()]
B = []
for i in range(N):
    B.append(sum(A[i*7:(i+1)*7]))
print(*B)