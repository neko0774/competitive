N, M = map(int, input().split())
mod = 10**9+7

def factorization(x):
    i = 2
    ans = []
    while i**2 <= x:
        e = 0
        while x%i == 0:
            e += 1
            x //= i
        if e>0:
            ans.append([i, e])
        i += 1
    if x!=1: ans.append([x, 1])
    return ans

def comb(n, k):#with mod
    a = 1
    b = 1
    for i in range(k):
        a = a*(n-i)%mod
        b = b*(i+1)%mod
    return a * pow(b, mod-2, mod)%mod
ans = 1
for _, i in factorization(M):
    ans *= comb(N+i-1, i)
    ans %= mod
print(ans)