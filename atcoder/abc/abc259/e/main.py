def main():
    inf = 10**18
    N = int(input())
    count = dict()
    for i in range(N):
        m = int(input())
        for _ in range(m):
            p,e = map(int, input().split())
            if p in count:
                if count[p][0]==e:
                    count[p] = [e, -1]
                elif count[p][0]<e:
                    count[p] = [e, i]
            else:
                count[p] = [e, i]
    
    ans = set(i[1] for i in count.values() if i[1]!=-1)
    print(min(len(ans)+1, N))
main()