import sys
input = sys.stdin.readline
N, M = map(int, input().split())
G = [set() for _ in range(N)]
for _ in range(M):
    u, v= map(int, input().split())
    u -= 1
    v -= 1
    G[u].add(v)

from collections import deque
ans = 0
for s in range(N):
    q = deque([s])
    visited = set()
    while q:
        x = q.popleft()
        visited.add(x)
        for nx in G[x]:
            if nx in visited: continue
            elif nx<s:
                visited |= G[nx]
                visited.add(nx)
            q.append(nx)
    
    for x in visited:
        if x!=s and not x in G[s]:
            ans += 1
            G[s].add(x)
print(ans)