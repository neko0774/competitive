while True:
    N = int(input())
    i = 0
    if N==0:
        exit()
    if N==1:
        print(input())
        continue
    result = []
    for i in range(N):
        w = input()
        #print(result, w)


        if len(result)==0:
            result.append([0 if w[-1]=="+" else 1 for _ in range(2)])
        elif len(w)-2==len(result):
            if result[-1][0]==0:
                #+
                result[-1][-1]+= int(w[-1])
            else:
                #*
                result[-1][-1]*= int(w[-1])
        else:
            while len(result)>len(w)-1:
                _, v = result.pop()
                #print(result, v)
                if result[-1][0]==0:
                    #+
                    result[-1][-1]+= v
                else:
                    #*
                    result[-1][-1]*= v
            #print(result)
            if w[-1]=="+" or w[-1]=="*":
                result.append([0 if w[-1]=='+' else 1 for _ in range(2)])
            else:
                if result[-1][0]==0:
                    #+
                    result[-1][-1]+= int(w[-1])
                else:
                    #*
                    result[-1][-1]*= int(w[-1])
    while len(result)>1:
        _, v = result.pop()
        if result[-1][0]==0:
            result[-1][1]+=v
        else:
            result[-1][1]*=v
    print(result[0][-1]) 
