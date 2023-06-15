while True:
    N, M = map(int, input().split())
    if N==M==0:
        exit()
    score = [0]*N
    min_score = [0]*N
    for _ in range(M):
        S = [int(i)-1 for i in input().split()]
        for s in S[2:]:
            score[s] += 1+S[0]
        if len(S)==3:
            min_score[S[-1]] += 1+S[0]
    ans = 0
    mini = [10**12, -1]
    second_mini = [10**12, -1]
    for n, v in enumerate(min_score):
        if v<mini[0]:
            second_mini[0] = mini[0]
            second_mini[1] = mini[1]
            mini[0] = v
            mini[1] = n
        elif v<second_mini[0]:
            second_mini[0] = v
            second_mini[1] = n
    for n, v in enumerate(score):
        if mini[1]==n:
            ans = max(ans, v-second_mini[0])
        else:
            ans = max(ans, v-mini[0])
    print(ans+1)