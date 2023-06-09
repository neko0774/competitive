N = int(input())
S = [i for i in input()]

g = 0
ng = 0
for s in S:
    if s=="o":g += 1
    elif s=="x": ng += 1

print('Yes' if g>=1 and ng==0 else "No")