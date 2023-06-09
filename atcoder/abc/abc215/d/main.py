N, M = map(int, input().split())
A = [int(i) for i in input().split()]


def osak(x):
    t = [0]*(x+1)
    for n in range(2, x+1):
        if t[n]!=0: continue
        t[n] = 1
        for nn in range(2*n, x+1, n):
            t[nn] = n
    return t


divt = osak(10**5+1)
d = set()
for a in set(A):
    if divt[a]==1:
        d.add(a)
        continue
    while divt[a]!=0:
        if divt[a]==1:
            d.add(a)
            break
        d.add(divt[a])
        a //= divt[a]

t = [0]*(M+1)
t[0] = 1
for a in d:
    for n in range(a, M+1, a):
        t[n] = 1
ans = []
cnt=0
for n in range(M+1):
    if t[n]==0:
        ans.append(n)
        cnt += 1
print(cnt)
print(*ans, sep="\n")