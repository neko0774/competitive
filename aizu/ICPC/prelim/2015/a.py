while True:
    m, nmin, nmax = map(int, input().split())
    if m==nmin==nmax==0:
        exit()
    gap = -1
    ans = -1
    plast = int(input()) 
    for i in range(m-1):
        p = int(input())
        if gap<=plast-p and nmin<=i+1<=nmax:
            gap = plast-p
            ans = i+1
        plast = p
    print(ans)