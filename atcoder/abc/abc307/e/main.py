N, M = map(int, input().split())
mod = 998244353
F = [[0, M*(M-1)%mod]]
for i in range(N-2):
    A = [0, 0]
    A[0] = F[-1][1]%mod
    A[1] = (F[-1][0]*(M-1)+F[-1][1]*(M-2))%mod
    F.append(A)
print(F[-1][1])