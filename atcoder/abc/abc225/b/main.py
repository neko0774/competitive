N = int(input())
G =[[] for _ in range(N)]
for _ in range(N-1):
    a,b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

mx = 0
mn = N
for g in G:
    mx = max(mx, len(g))
    mn = min(mn, len(g))
print("Yes" if mx==N-1 and mn==1 else "No")