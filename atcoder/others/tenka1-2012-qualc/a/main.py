def osak(x):
    t = [0]*(x+1)
    for n in range(2, x+1):
        if t[n]!=0: continue
        t[n] = 1
        for nn in range(2*n, x+1, n):
            t[nn] = n
    return t
N = int(input())
t = osak(N-1)
ans = t.count(1)
print(ans)