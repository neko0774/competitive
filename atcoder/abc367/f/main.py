#https://tech.aru-zakki.com/rollinghash-on-segtree/#google_vignette

# --- セグメント木 -----
class segtree():
    n=1
    size=1
    log=2
    d=[0]
    op=None
    e=10**15
    def __init__(self,V,OP,E):
        self.n=len(V)
        self.op=OP
        self.e=E
        self.log=(self.n-1).bit_length()
        self.size=1<<self.log
        self.d=[E for i in range(2*self.size)]
        for i in range(self.n):
            self.d[self.size+i]=V[i]
        for i in range(self.size-1,0,-1):
            self.update(i)
    def set(self,p,x):
        assert 0<=p and p<self.n
        p+=self.size
        self.d[p]=x
        for i in range(1,self.log+1):
            self.update(p>>i)
    def get(self,p):
        assert 0<=p and p<self.n
        return self.d[p+self.size]
    def prod(self,l,r):
        assert 0<=l and l<=r and r<=self.n
        sml=self.e
        smr=self.e
        l+=self.size
        r+=self.size
        while(l<r):
            if (l&1):
                sml=self.op(sml,self.d[l])
                l+=1
            if (r&1):
                smr=self.op(self.d[r-1],smr)
                r-=1
            l>>=1
            r>>=1
        return self.op(sml,smr)
    def all_prod(self):
        return self.d[1]
    def update(self,k):
        self.d[k]=self.op(self.d[2*k],self.d[2*k+1])
    def __str__(self):
        return str([self.get(i) for i in range(self.n)])
    

# ----- ここからメインプログラム　--------
N, Q = map(int, input().split())

# 文字列Sと逆順のTを作成。同時に整数値に変換
s = [int(i) for i in input().split()]
t = [int(i) for i in input().split()]


# 素数
p = 998244353

# xをランダムに生成
import random
x = random.randint(10000, p) % p

# セグメント木にのせるデータに変換
s = [[e, x, p] for e in s]
t = [[e, x, p] for e in t]

# funcの定義
def op(x, y) :
    h0, x0, p = x
    h1, x1, p = y
    return [(h0 + h1 * x0)%p, (x0*x1)%p, p]

# セグメント木の生成
segS = segtree(s, op, [0,1,p])
segT = segtree(t, op, [0,1,p])

# ループ
for _ in range(Q) :
    l, r, L, R = map(int, input().split())
    l -= 1
    r -= 1
    L -= 1
    R -= 1
    h0 = segS.prod(l, r)[0]
    h1 = segT.prod(L, R)[0]
    #print(h0, h1)
    print("Yes" if h0 == h1 else "No")
#print(segS.__str__(), segT.__str__())