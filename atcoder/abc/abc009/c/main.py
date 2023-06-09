from collections import defaultdict
def main():
    N, K = map(int, input().split())
    S = [i for i in input()]
    C = dict()
    mobile = defaultdict(int)
    is_change = set()
    for n, s in enumerate(S):
        if s in C:
            C[s].append(n)
        else:
            C[s] = [n]
    for i in range(N):
        #print(i, is_change, K, S, mobile, C)
        s = S[i]
        if i in is_change:
            for a in range(ord("z")-ord("a")+1):
                a = chr(a+ord("a")) 
                if mobile[a]>0:
                    S[i] = a
                    mobile[a] -= 1
                    break
                elif a in C and C[a] and C[a][-1]>i and K>0:
                    K -= 1
                    index = C[a].pop()
                    S[i] = a
                    is_change.add(index)
                    break
        else:
            for a in range(ord(s)-ord("a")):
                a = chr(a+ord("a"))
                if mobile[a]>0 and K>0:
                    K -= 1
                    S[i] = a 
                    mobile[a] -= 1
                    mobile[s] += 1
                    break
                elif a in C and C[a] and C[a][-1]>i and K>=2:
                    K -= 2
                    index = C[a].pop()
                    mobile[s] += 1
                    S[i] = a
                    is_change.add(index)
                    break
    print("".join(S))
main()