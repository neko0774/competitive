a, b, c, d = map(int, input().split())
buf = 0
a += buf
b += buf
c += buf
d += buf
R = c//4 * 4
L = a//4 * 4
D = b//2 * 2
T = d//2 * 2
print(R, L, D, T)
ans = 4*((R-L)//4)*((T-D)//2)
print(ans)