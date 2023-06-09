N = int(input())
S = [1 if i=="#" else 0 for i in input()]
def factorization(x):
    i = 2
    ans = []
    while i**2 <= x:
        e = 0
        while x%i == 0:
            e += 1
            x //= i
        if e>0:
            ans.append(i)
        i += 1
    if x!=1: ans.append(x)
    return ans

mod = 998244353
Ms = [N//i for i in factorization(N)[::-1]]
ans = 0
for cnt in Ms:
    check = [0]*cnt
    for n in range(N//cnt):
        for i in range(cnt):
            if not S[i+n*cnt]: check[i] = 1
    print(cnt, check)
    ans += pow(2, cnt-sum(check), mod)
    ans %= mod
print((ans-len(Ms)+1)%mod)
    