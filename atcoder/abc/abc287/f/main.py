mod = 998244353
def main():
    N = int(input())
    G = [[] for _ in range(N)]
    for _ in range(N):
        a,b = map(int, input().split())
        a -= 1
        b -= 1
        G[a].append(b)
        G[b].append(a)
        
    ans = [0]*N
    #chose i vertex
    #

    for i in range(N):
        for j in ragne(i+1):
            
    



main()