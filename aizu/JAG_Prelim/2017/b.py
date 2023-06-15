while True:
    T, D, L = map(int, input().split())
    if T==D==L==0:
        exit()
    ans = 0
    d = 0
    for _ in range(T-1):
        x = int(input())
        if x>=L:
            ans += 1
            d = D
        elif d>0:
            ans += 1
        d -= 1
    _ = input()
    print(ans)