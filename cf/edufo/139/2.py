T = int(input())
def solve():
    N = int(input())
    S = input()
    ans = 0
    ls = ""
    use = set()
    last = set([''])
    for s in S:
        s = ls+s
        if s in use:
            ls = s
        else:
            use = use.union(nuse)
            ans += 1
            s = s[-1]
            if s in use:
                ls = s
            elif ls:
                ls = ""
                ans += 1
        nuse = set([''])
        for lst in last:
            nuse.add(lst+s[-1])
        last = nuse
        print(use, ans)
    if ls: ans += 1
    print(use, ls, ans)
    print("Yes" if ans<N else "No")
            
        




for _ in range(T):
    solve()