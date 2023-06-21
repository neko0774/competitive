from heapq import heappop, heappush
inf = 10**12
while True:
    N, M, L, K, A, H = map(int, input().split())
    if N==M==L==K==A==H==0: exit()
    if L: city = set([int(i) for i in input().split()])
    G = [[] for _ in range(N)]
    for i in range(K):
        x,y,t = map(int, input().split())
        if t<=M:
            G[x].append((y, t))
            G[y].append((x, t))
    time = [inf]*N
    maxM = [0]*N
    maxM[A] = M
    seen = [0]*N
    hq = [(0, A, M)]
    dist[A] = 0
    print(G)
    while hq:
        t, v, m = heappush(hq)
        for to, w in G[v]:
            if v in city:
                if maxM[to]<M-w:
                    #update
            else:
                if maxM[to]<m-w:
                    #update