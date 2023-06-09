def main():
    W = int(input())
    N, K = map(int, input().split())
    dp = [[0]*(K+1) for _ in range(W+1)]
    for i in range(N):
        A, B = map(int, input().split())
        ndp = [[0]*(K+1) for _ in range(W+1)]
        for w in range(W+1):
            for k in range(1, K+1):
                if w-A>=0:ndp[w][k] = max(dp[w][k], dp[w-A][k-1]+B)
                else: ndp[w][k] = dp[w][k]

        dp = ndp
    
    print(max([max(i) for i in dp]))
    

main()