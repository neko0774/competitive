from collections import deque


def main():
    N = int(input())
    S = input()
    cnt = 0
    sp = 0
    q = deque()
    for s in S:
        q.append([s, 0])
        if len(q)>=3:
            if q[-3][0]=="A" and q[-2][0]=="R" and q[-1][0]=="C":
                if q[-2][1]==1:
                    sp += 1
                else:
                    cnt += 1        
                q.pop()
                q.pop()
                q.pop()
                q.append(["R", 1])
    print(cnt+sp if cnt>=sp else cnt*2) 
main()