Q = int(input())

def osak(x):
    t = [0]*(x+1)
    for n in range(2, x+1):
        if t[n]!=0: continue
        t[n] = 1
        for nn in range(2*n, x+1, n):
            t[nn] = n
    return t

t = osak(10**5+7)
count = [0]*(10**5+7)
for n in range(1, 10**5+3):
    if n%2==1 and t[n]==1 and t[(n+1)//2]==1: count[n]+=1
    count[n] += count[n-1]
for _ in range(Q):
    l, r= map(int, input().split())
    print(count[r]-count[l-1])