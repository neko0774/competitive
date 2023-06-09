def main():
    t = [int(i) for i in input().split()]
    T = [int(i) for i in input().split()]
    A = [int(i) for i in input().split()]

    takahashi = t[0]*T[0]+t[1]*T[1]
    aoki = t[0]*A[0]+t[1]*A[1] 

    if takahashi==aoki:
        print("infinity")
        return
    
    if takahashi>aoki:
        fa = T
        sl = A
    else:
        sl = T
        fa = A

    dif = abs(takahashi-aoki)
    if fa[0]>sl[0]:
        print(0)
    else:
        ans = (sl[0]-fa[0])*t[0]//dif*2
        if (sl[0]-fa[0])*t[0]%dif!=0: ans += 1
        print(ans)




main()