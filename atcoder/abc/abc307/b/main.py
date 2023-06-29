def is_parin(x):
    for i in range(len(x)//2):
        if x[i]!=x[-i-1]: return 0
    return 1



S = []
N = int(input())
for _ in range(N):
    ss = input()
    for s in S:
        if is_parin(s+ss) or is_parin(ss+s):
            print("Yes")
            exit()
    S.append(ss)
print("No")