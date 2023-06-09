N, X, Y = map(int, input().split())
A = [int(i) for i in input().split()]

ans = 0
low_dur = 0
for a in A:
    if a<=X:
        low_dur += 1

if X>Y:
    print(N)
else:
    print((low_dur+1)//2)