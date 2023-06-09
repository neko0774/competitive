N = int(input())
K = int(input())

mod = 10**9+7

def comb(n, k):#with mod
    a = 1
    b = 1
    for i in range(k):
        a = a*(n-i)%mod
        b = b*(i+1)%mod
    return a * pow(b, mod-2, mod)%mod

print(comb(N+K-1, K))