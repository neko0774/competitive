N = 10**6
table = [0]*N
table[0] = -1
table[1] = -1
for i in range(2, N):
    if table[i]!=0: continue
    for j in range(2*i, N, i):
        table[j] = i
count = [0]*N
for t in range(1, N):
    if  table[t]==0: count[t] = count[t-1]+1
    else: count[t] = count[t-1]
while True:
    n = int(input())
    if n==0: exit()
    print(count[2*n]-count[n])