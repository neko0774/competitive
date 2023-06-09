H, W, A, B = map(int, input().split())
mod = 10**9+7
fact = [1]
for i in range(1, 10**6):
    fact.append(fact[-1]*i%mod)
fact_inv = [pow(fact[-1], mod-2, mod)]
for i in range(1, 10**6-1)[::-1]:
    fact_inv.append(fact_inv[-1]*i%mod)

ans = 0
for i in range(W-B):
    ans += fact[B+i+H-A-1]*fact_inv[B+i]*fact_inv[H-A-1] * fact[W-B+i+A]*fact_inv[W-B+i]*fact_inv[A-2]%mod
    ans %= mod
print(ans%mod)