mod = 10**9+7
NN = 3*10**5
fac = [0]*NN
finv = [0]*NN
inv = [0]*NN
fac[0] = fac[1] = 1
finv[0] = finv[1] = 1
inv[1] = 1
for i in range(2, NN):
    fac[i] = fac[i-1]*i%mod
    inv[i] = mod-inv[mod%i]*(mod//i)%mod
    finv[i] = finv[i-1]*inv[i]%mod

def comb(a, b, p=10**9+7):
    if a<b: return 0
    elif a<0 or b<0: return 0
    return fac[a]*(finv[b]*finv[a-b]%p)%p



N, K = map(int, input().split())
ans = 0
for i in range(min(N, K+1)):
    ans += comb(N, i)%mod*comb(N-1,i)%mod
    ans %= mod
    #print(i, ans)
print(ans)