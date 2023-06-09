N, M = map(int, input().split())
A = [int(i) for i in input().split()]

t = [0]*(M+1)
t[0] = 1
cnt = M
if max(A)!=1:
    t[1] = 1
    cnt -= 1
for a in set(A):
    if t[a]==1: continue
    for n in range(a, M+1, a):
        t[n] = 1
        cnt -= 1
print(cnt)
for n in range(M+1):
    if t[n]==0: print(n)