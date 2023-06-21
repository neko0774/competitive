N = int(input())
xor = 0
for _ in range(N):
    X, Y, Z = map(int, input().split())
    X -= 1
    Y -= 1
    Z -= 1
    xmn = X
    xmx = 0
    ymn = Y
    ymx = 0
    zmn = Z
    zmx = 0
    M = int(input())
    for _ in range(M):
        x, y, z = map(int, input().split())
        xmn = min(xmn, x)
        xmx = max(xmx, x)
        ymn = min(ymn, y)
        ymx = max(ymx, y)
        zmn = min(zmn, z)
        zmx = max(zmx, z)
    xor ^= xmn^ymn^zmn^(X-xmx)^(Y-ymx)^(Z-zmx)

print("LOSE" if xor==0 else "WIN")