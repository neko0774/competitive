import sys
sys.setrecursionlimit(10**7)
mod = 10**9+7
import pypyjit
pypyjit.set_param('max_unroll_recursion=-1')
def main():
    N = int(input())
    G = [[] for _ in range(N)]
    for _ in range(N-1):
        u,v = map(int, input().split())
        u -= 1
        v -= 1
        G[u].append(v)
        G[v].append(u)
    
    dp = [[0, 0] for _ in range(N)]
    #0 = black
    #1 = whilte
    seen = [0]*N
    def dfs(x):
        seen[x] = 1
        dp[x] = [1, 1]
        for nx in G[x]:
            if seen[nx]: continue
            dfs(nx)
            dp[x][0] *= (dp[nx][1]+dp[nx][0])
            dp[x][1] *= dp[nx][0]
            dp[x][0] %= mod
            dp[x][1] %= mod
    dfs(0)
    print(sum(dp[0])%mod)
        

main()