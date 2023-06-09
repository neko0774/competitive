from collections import deque
def main():
    inf = 10**12
    M = int(input())
    G = [[] for _ in range(9)]
    for _ in range(M):
        u,v = map(int, input().split())
        u -= 1
        v -= 1
        G[u].append(v)
        G[v].append(u)
    P = [int(i)-1 for i in input().split()]

    q = deque(["".join(map(str, P))])
    dp = dict()
    dp[q[0]] = 0
    while q:
        cur = q.popleft()
        unused = 36-sum([int(i) for i in cur])
        pos = [-1]*9
        for n,i in enumerate(cur):
            pos[int(i)] = n
        for v in G[unused]:
            #print(pos, unused, dp[cur])
            ncur = [i for i in cur]
            ncur[pos[v]] = str(unused)
            ncur = "".join(ncur)
            if ncur in dp: continue
            else:
                dp[ncur] = dp[cur]+1
                q.append(ncur)
    
    print(-1 if not "01234567" in dp else dp["01234567"])


        


main()