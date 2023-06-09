def main():
    N = int(input())
    G = [[] for _ in range(N)]
    for _ in range(N-1):
        a,b = map(int, input().split())
        a -= 1
        b -= 1
        G[a].append(b)
        G[b].append(a)
    #draw the vertex i at jth time
    def dfs(x, par=-1):
        for nx in G[x]:
            if nx==par: continue
            dfs(nx, x)
            dp[x] += dp[nx]
            
    for n in range(N):
        dp = [0]*N
        seen = [0]*N
        dfs(n)
        

    dfs(0)
    
main()