def inv_gcd(a,b):
    a=a%b
    if a==0:
        return (b,0)
    s=b;t=a
    m0=0;m1=1
    while(t):
        u=s//t
        s-=t*u
        m0-=m1*u
        s,t=t,s
        m0,m1=m1,m0
    if m0<0:
        m0+=b//s
    return (s,m0)
def inv_mod(x,m):
    assert 1<=m
    z=inv_gcd(x,m)
    assert z[0]==1
    return z[1]
def crt(r,m):
    assert len(r)==len(m)
    n=len(r)
    r0=0;m0=1
    for i in range(n):
        assert 1<=m[i]
        r1=r[i]%m[i]
        m1=m[i]
        if m0<m1:
            r0,r1=r1,r0
            m0,m1=m1,m0
        if (m0%m1==0):
            if (r0%m1!=r1):
                return (0,0)
            continue
        g,im=inv_gcd(m0,m1)
        u1=m1//g
        if ((r1-r0)%g):
            return (0,0)
        x=(r1-r0)//g % u1*im%u1
        r0+=x*m0
        m0*=u1
        if r0<0:
            r0+=m0
    return (r0,m0)

def main():
    P = [4, 9, 5, 7, 11, 13, 17, 19, 23]
    
    A = []
    S = []
    for p in P:
        s = len(A)+1
        S.append(s-1)
        for i in range(1, p):
            A.append(s+i) 
        A.append(s)

    print(len(A))
    print(*A)

    B = [int(i) for i in input().split()]
    BB =  []
    for i in range(len(P)):
        s = S[i]
        b = B[s]
        p = P[i]
        BB.append(b-A[s]+1)
    print(crt(BB, P)[0])

main()
