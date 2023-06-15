from heapq import heappush, heappop
from collections import deque
while True:
    N = int(input())
    if N==0:
        exit()
    V = []
    G = [[] for _ in range(N)]
    for n in range(N):
        x, y, z = map(int, input().split())
        V.append([max(x, y, z), x+y+z-max(x,y,z)-min(x,y,z), min(x,y,z), x*y*z])
    
    root = set([i for i in range(N)])
    no_incoming_edges = [0]*N
    for v in range(N):
        for nv in range(N):
            if v==nv: continue
            if V[v][0]>V[nv][0] and V[v][1]>V[nv][1] and V[v][2]>V[nv][2]:
                heappush(G[v], (-V[nv][-1], nv))
                no_incoming_edges[nv] += 1
    #print(V)
    #print(G)
    seen = [0]*N
    ans = 0
    todo = deque()
    for n, v in enumerate(no_incoming_edges):
        if v==0: todo.append(n)
    #print(no_incoming_edges, todo)
    while todo:
        x = todo.popleft()
        ans += V[x][-1]
        seen[x] = 1
        while x!=-1:
            nx = -1
            is_changed = 0
            while G[x]:
                nv = heappop(G[x])[1]
                no_incoming_edges[nv] -= 1
                if not seen[nv] and not is_changed:
                    seen[nv] = 1
                    is_changed = 1
                    nx = nv
                if no_incoming_edges[nv]==0 and not seen[nv]:
                    todo.append(nv)
            x = nx
            #print(todo, nx, seen, ans)assert 
    print(ans)