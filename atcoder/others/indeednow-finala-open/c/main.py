def main():
    N, M = map(int, input().split())
    dp = [[[0 for _ in range(101)] for _ in range(101)] for _ in range(101)]
    for _ in range(N):
        a,b,c,w = map(int, input().split())
        dp[c][b][a] = max(dp[c][b][a], w)
    for c in range(101):
        for b in range(101):
            for a in range(101):
                if a<100:dp[c][b][a+1] = max(dp[c][b][a+1], dp[c][b][a])
                if b<100:dp[c][b+1][a] = max(dp[c][b+1][a], dp[c][b][a])
                if c<100:dp[c+1][b][a] = max(dp[c+1][b][a], dp[c][b][a])

    for _ in range(M):
        a,b,c = map(int, input().split())
        print(dp[c][b][a])
main()