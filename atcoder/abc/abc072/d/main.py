N = int(input())
P = [int(i)-1 for i in input().split()]
cnt = 0
for i in range(N):
    if P[i] == i:
        if i!=N-1: P[i], P[i+1] = P[i+1], P[i]
        cnt += 1
print(cnt)