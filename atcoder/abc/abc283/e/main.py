def main():
    H, W = map(int, input().split())
    A = [[int(i) for i in input().split()] for _ in range(H)]
    def solve(A, rev):
        rrv = []
        print(A)
        ret = rev
        cnt = 0

        c1, c2 = [0]*W, [0]*W
        h = 0
        for w in range(W):
            if (w>0 and A[h][w-1]==A[h][w]) or A[h+1][w]==A[h][w] or (w+1<W and A[h][w+1]==A[h][w]):
                c1[w] = 1
            if (w>0 and A[h][w-1]==A[h][w]) or A[h+1][w]!=A[h][w] or (w+1<W and A[h][w+1]==A[h][w]):
                c2[w] = 1
        #print(c1, c2)
        if 0 in c1 and 0 in c2:
            return -1

        for h in range(1, H-1):
            clear1 = [0]*W
            #stay
            clear2 = [0]*W
            #reversed 
            for w in range(W):
                if (w>0 and A[h][w-1]==A[h][w]) or A[h-1][w]==A[h][w] or (w+1<W and A[h][w+1]==A[h][w]):
                    clear1[w] = 1
                if (w>0 and A[h][w-1]==A[h][w]) or A[h-1][w]!=A[h][w] or (w+1<W and A[h][w+1]==A[h][w]):
                    clear2[w] = 1
            #heraseru
            if rev:
                clear1, clear2 = clear2, clear1
            print(1, clear1, clear2)
            stay_clear = clear1
            rev_clear = clear2
            for w in range(W):
                if A[h+1][w]==A[h][w]:
                    clear1[w] = 1
                    rev_clear[w] = 1
                else:
                    clear2[w] = 1
                    stay_clear[w] = 1
            print(2, clear1, stay_clear, clear2, rev_clear)
                
            if not 0 in clear1 or not 0 in stay_clear:
                rev = False
                rrv.append(0)
            elif not 0 in clear2 or not 0 in rev_clear:
                rrv.append(1)
                rev = True
                ret += 1
            else:
                return -1
            
        c1, c2 = [0]*W, [0]*W
        h = -1
        for w in range(W):
            if (w>0 and A[h][w-1]==A[h][w]) or A[h-1][w]==A[h][w] or (w+1<W and A[h][w+1]==A[h][w]):
                c1[w] = 1
            if (w>0 and A[h][w-1]==A[h][w]) or A[h-1][w]!=A[h][w] or (w+1<W and A[h][w+1]==A[h][w]):
                c2[w] = 1
        if rev:
            c1, c2 = c2, c1
        print(A, rrv)
        if not 0 in c1:
            return ret
        elif not 0 in c2:
            return ret+1
        else:
            return -1

    s1 = solve(A, 0)
    for w in range(W):
        A[0][w] = 1-A[0][w]
    s2 = solve(A, 1)
    print(s1, s2)
    if s1==s2==-1:
        print(-1)
    elif s1==-1:
        print(min(s2, H-s2))
    elif s2==-1:
        print(min(s1, H-s1))
    else:
        print(min(s1, s2, H-s1, H-s2))



            
    
main()