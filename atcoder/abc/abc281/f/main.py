def main():
    N = int(input())
    A = [int(i) for i in input().split()]

    #search from the highest bit
    #at the next bit, if it is possible not to have 1s at one before and the current one
    #use it
    #else 
    #add and continue
    b1 = set()
    b2 = set([i for i in range(N)])
    ans = 0

    def f(x, y):
        return len(x.intersection(y))

    for i in range(31)[::-1]:
        c1 = set()
        c2 = set()
        for n,a in enumerate(A):
            if a&1<<i: c1.add(n)
            else: c2.add(n)
        if len(b1)==0 and len(c1)!=0 and ans ==0:
            ans += 2**i 
        elif max(min(f(b1, c1), f(b1, c2)), min(f(b2, c1), f(b2, c2)))==0:
            pass
        else:
            ans += 2**i
        print(b1, b2, c1, c2)
        b1, b2 = c1, c2
    print(ans)
        



main()