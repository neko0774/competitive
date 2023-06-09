from math import gcd
def solve():
    N, D, K = map(int, input().split())
    n = gcd(N, D)
    K -= 1
    if n==1:
        print(D*K%N)
    else:
        NN = N//n
        k = K//NN
        KK = K%NN
        print((k+KK*D)%N)
T = int(input())
for _ in range(T): solve()