N, W = map(int, input().split())
bag = [[int(i) for i in input().split()] for _ in range(N)]

from bisect import bisect_left as bl
def hanbun(N, W, bag):
    f = [[0, 0]]
    s = [[0, 0]]
    ret = 0
    for v,w in bag[:N//2]:
        for i in range(len(f)):
            if w+f[i][0]<=W: f.append([w+f[i][0], v+f[i][1]])
    for v,w in bag[N//2:]:
        for i in range(len(s)):
            if w+s[i][0]<=W: s.append([w+s[i][0], v+s[i][1]])
    s.sort()
    v = 0
    for i in range(len(s)):
        v = max(s[i][1], v)
        s[i][1] = v

    def bin_search(x):
        ret = 0
        ok, ng = 0, len(s)
        while abs(ng-ok)>1:
            mid = (ok+ng)//2
            if s[mid][0]<=x:
                ok = mid
            else:
                ng = mid
        return s[ok][-1]
    for w,v in f:
        ret = max(ret, bin_search(W-w)+v)
    return ret

def solve(N, W, bag):
    maxv = max([v for v,_ in bag])
    maxw = max([w for _,w in bag])
    if maxv<=1000:
        dp = [[10**18]*(N*maxv+5) for _ in range(N+1)]
        for n,item in enumerate(bag):
            v,w = item
            dp[n][0] = 0
            for vv in range(N*maxv+5):
                if vv-v>=0:dp[n+1][vv] = min(dp[n][vv], dp[n][vv-v]+w)
                else: dp[n+1][vv] = dp[n][vv]

        for v in range(N*maxv+5)[::-1]:
            if dp[-1][v]<=W:
                return v
    else:
        dp = [[0]*(N*maxw+5) for _ in range(N+1)]
        for n,item in enumerate(bag):
            v,w = item
            for ww in range(N*maxw+5):
                if ww-w>=0:dp[n+1][ww] = max(dp[n][ww], dp[n][ww-w]+v)
                else: dp[n+1][ww] = dp[n][ww]

        ret = 0
        for w in range(min(N*maxw+5, W+1)):
            ret = max(ret, dp[-1][w]) 
        return ret

print(hanbun(N, W, bag) if N<=30 else solve(N, W, bag))