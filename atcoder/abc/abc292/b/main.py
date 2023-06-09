N, Q =map(int, input().split())
X = [0]*N
for _ in range(Q):
    c, x = map(int, input().split())
    x -= 1
    if c==1:
        X[x] += 1
    elif c==2:
        X[x] += 2
    else:
        print("Yes" if X[x]>=2 else "No")