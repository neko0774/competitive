K = int(input())
N = 50
s = N * (N-1) // 2
a = K // N
b = K % N
A = [a + i + (1 if i >= N-b else 0) for i in range(N)]
print(len(A))
print(*A)