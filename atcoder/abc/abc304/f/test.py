import random as rd
mod = 998244353
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




def test(N, S):
    cnt = 0
    Ms = [N//i for i in factorization(N)[::-1]]
    def is_repated(iter):
        for m in Ms:
            flag = 1
            base = iter[:m]
            for l in range(m, N, m):
                if base!=iter[l:l+m]: flag = 0
            if flag: return 1
        return 0
    import itertools as it
    for iter in it.product([0,1], repeat=N):
        cnt += is_repated(iter)
        cnt %= mod
    return cnt


def solve(N, S):
    ans = 0
    Ms = [N//i for i in factorization(N)[::-1]]
    for cnt in Ms:
        check = [0]*cnt
        for n in range(N//cnt):
            for i in range(cnt):
                if not S[i+n*cnt]: check[i] = 1
        #print(cnt, check)
        ans += pow(2, cnt-sum(check), mod)
        ans %= mod
    ans -= len(Ms)-1
    return ans
for i in range(20):
    N = rd.randint(2, 20)
    S = ["#" if rd.randint(0, 100)>50 else "." for _ in range(N)]
    if not solve(N, S)==test(N, S):
        print(solve(N, S))
        print(test(N, S))
        print(N, S)