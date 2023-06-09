from bisect import bisect_left as bl
def main():
    A, B, Q = map(int, input().split())
    S = [int(input()) for _ in range(A)]
    T = [int(input()) for _ in range(B)]

    def solve(x):
        s = bl(S, x)
        t = bl(T, x)
        if s==A:
            sl, sr = s-1, s-1
        else:
            sl, sr = max(0, s-1), s
        if t==B:
            tl, tr = t-1, t-1
        else:
            tl, tr = max(0, t-1), t
        ret = 10**18
        #print(sl, sr, tl , tr)
        for s in [S[sl] ,S[sr]]:
            for t in [T[tl], T[tr]]:
                ret = min(ret, abs(x-s)+abs(s-t), abs(x-t)+abs(s-t))
        return ret


    for _ in range(Q):
        x = int(input())
        print(solve(x))
main()