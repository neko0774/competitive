from bisect import bisect_right as br
def main():
    S = [i for i in input()]
    T = [i for i in input()]
    word = dict()
    for n,s in enumerate(S):
        if s in word:
            word[s].append(n+1)
        else:
            word[s] = [n+1]
    cnt = 0
    p = 0
    for t in T:
        if not t in word:
            print(-1)
            return
        np = br(word[t], p)
        if np==len(word[t]):
            cnt += 1
            p = word[t][0]
        else:
            p = word[t][np]
    print(cnt*len(S)+p)
main()