N, M = map(int, input().split())
G = []
for _ in range(M):
    a,b,c = map(int, input().split())
    a -= 1 
    b -= 1
    G.append((a,b,-c))

inf = 10**12
dist = [inf]*N
dist[0] = 0
cnt = 0
#rikai
#even though a negative cycle exits as long as it does not involve 0 and N-1
#it should not return inf
while True:
    update = 0
    neg_update = 0
    for f,to,c in G:
        if dist[f]!=inf and dist[to]>dist[f]+c:
            dist[to] = dist[f]+c
            update = 1
            if to==N-1: neg_update = 1
    if not update: break
    cnt += 1
    if cnt==N and neg_update:
        print("inf")
        exit()
    elif cnt==N:
        break
print(-dist[-1])