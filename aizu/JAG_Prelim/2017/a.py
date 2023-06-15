while True:
    N, M = map(int, input().split())
    if N==M==0:
        exit()
    
    questions = [-1]*M
    for _ in range(N):
        d, v = map(int, input().split())
        d -= 1
        questions[d] = max(questions[d], v)
    print(sum(questions))