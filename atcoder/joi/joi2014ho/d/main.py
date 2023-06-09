N, M, X = map(int, input().split())
H = [int(input()) for _  in range(N)]
G = [[] for _ in range(N)]
for _ in range(M):
    a,b,t = map(int, input().split())
    a -= 1
    b -= 1
    if H[a]>=t: G[a].append((b, t))
    if H[b]>=t: G[b].append((a, t))

inf = 10**18
from heapq import heappop, heappush
time = [inf]*N
hq = [(0, 0)]
time[0] = 0
while hq:
    x, cur_time = heappop(hq)
    if cur_time>time[x]: continue
    for to, cost in G[x]:
        #print(H[x], cost, time[to], time[x])
        h = max(0, X-time[x])
        if h-H[to]>cost:
            dif = h-H[to]
        elif cost>h:
            dif = cost*2-h
        else:
            dif = cost
        
        if time[to]>time[x]+dif:
            time[to] = time[x]+dif
            heappush(hq, (to, time[to]))
            
print(-1 if time[-1]==inf else time[-1]+H[-1]-max(0, X-H[-1]))