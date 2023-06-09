inf = 10**12
def main():
    N, M = map(int, input().split())

    key = []
    C = []
    for _ in range(M):
        a,b = map(int, input().split())
        key.append([a,b])
        c = [int(i)-1 for i in input().split()]
        C.append(c)

    for i in range(M):
        cnt = 0
        for c in C[i]:
            cnt += 1<<c
        key[i].append(cnt)
    dp = [inf for _ in range(1<<N)]
    for i in range(M):
        dp[0] = 0
        ndp = dp
        for j in range(1<<N):
            ndp[j|key[i][-1]] = min(ndp[j|key[i][-1]], dp[j]+key[i][0])
    print(-1 if ndp[-1]==inf else ndp[-1])


main()