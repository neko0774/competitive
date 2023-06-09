import sys
sys.setrecursionlimit(10**9)
def main():
    N = int(input())
    G = [[] for _ in range(2*N)]
    for i in range(N):
        G[i].append(i+N)
    T = dict()
    S = []
    for i in range(N):
        s, t = input().split()
        S.append(t)
        T[s] = i
    for n,s in enumerate(S):
        if s in T:
            G[n+N].append(T[s])
    seen = [[0, -1]]*2*N
    def dfs(x, turn):
        seen[x] = [1, turn]
        for nx in G[x]:
            if seen[nx][0] and seen[nx][1]==turn:
                print("No")
                exit()
            elif seen[nx][0]:
                return
            dfs(nx, turn)

    cnt = 1
    for i in range(N):
        if not seen[i][0]:
            dfs(i, cnt)
            cnt += 1
    print("Yes")
main()