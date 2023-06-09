N = int(input())
S = input()

for i in range(1, N):
    flag = True
    for j in range(N-i):
        if S[j]==S[j+i]:
            print(j)
            flag = False
            break
    if flag: print(N-i)