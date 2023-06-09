def count(S):
    p = [[S[0], 1]]
    for s in S[1:]:
        if p[-1][0]==s:
            p[-1][1] += 1
        else:
            p.append([s, 1])
    ret = 0
    for pp,n in p:
        ret += n//2
    return ret

from collections import deque
def main():
    S = input()
    K = int(input())
    if len(set([i for i in S]))==1:
        print((len(S)*K)//2)
    elif S[0]==S[-1]:
        cnt = 0
        f = S[0]
        bb = 0
        for s in S:
            if s==f: cnt += 1
            else: break
        for s in S[::-1]:
            if s==f: bb += 1
            else: break
        ans = count(S[cnt:]+f*cnt)*(K-1)+count(S)
        print(ans)
    else:
        print(count(S)*K)

    
        
                


main()