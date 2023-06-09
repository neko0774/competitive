N = int(input())
def osak(x):
    t = [0]*(x+1)
    for n in range(2, x+1):
        if t[n]!=0: continue
        t[n] = 1
        for nn in range(2*n, x+1, n):
            t[nn] = n
    return t

t = osak(60000)

ans= []
for i in range(1, 55556, 5):
    if t[i]==1: ans.append(i)
print(*ans[:N])