from collections import deque
def main():
    N = int(input())
    A = [int(i) for i in input().split()]
    S = [[i for i in input()] for _ in range(N)]
    Q = int(input())

    G = [[] for _ in range(N)]
    for x in range(N):
        for y in range(N):
            if S[x][y]=="Y": G[x].append(y)
    
    def solve(x):   
        q = deque([[x, 0]])
        dist = [[-1, 0] for _ in range(N)]
        dist[x][0] = 0
        dist[x][1] = A[x]
        while q:
            x, d = q.popleft()
            for nx in G[x]:
                if dist[nx][0]==-1:
                    dist[nx][0] = d+1
                    dist[nx][1] = max(dist[nx][1], dist[x][1]+A[nx])
                    q.append([nx, d+1])
                elif  dist[nx][0]==d+1:
                    dist[nx][1] = max(dist[nx][1], dist[x][1]+A[nx])
        return dist
        

    ans = []
    for x in range(N):
        ans.append(solve(x))
    for _ in range(Q):
        u,v = map(int, input().split())
        u -= 1
        v -= 1
        if ans[u][v][0]==-1:
            print("Impossible")
        else:
            print(*ans[u][v])
main()