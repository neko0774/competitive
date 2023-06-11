length = [5, 7, 5, 7, 7]

while True:
    N = int(input())
    if N==0: exit()
    
    W = [len(input()) for _ in range(N)]
    #print(W)
    for i in range(N):
        idx = 0
        size = 0
        flag = 0
        for w in W[i:]:
            size += w
            #print(idx, w, size)
            if length[idx]==size:
                idx += 1
                size = 0
                if idx==5:
                    flag=1
                    ans = i+1
                    break
            elif length[idx]>size:
                continue
            else:
                break
            
        if flag:
            break
    print(ans)