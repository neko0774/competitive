from collections import deque
def solve():
    N = int(input())
    S = [int(i) for i in input()]
    if sum(S)%2!=0:
        print(-1)
        return
    cnt = 0
    count = dict()
    num = deque([0]+S[:2])
    for i in range(2, N):
        num.append(S[i])
        num.popleft()

        if sum(num)>=2:
            cnt += 1
            if num[0]==num[1]:
                num[0]=0
                num[1]=0
            elif num[0]==num[2]:
                num[0]=0
                num[2]=0
            else:
                num[1]=0
                num[2]=0
        
        if num[0]==1:
            cnt += 1
            num[0] = 0
            num[-1] = 1

    print(cnt)


        
    



    


T = int(input())
for _ in range(T):
    solve()

