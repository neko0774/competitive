N = int(input())
num = dict()
nx = dict()
ny = dict()
NN = []
X = set()
Yy = set()
def v(x, y): return 10**9*x+y
for _ in range(N):
    x,y,r = map(int, input().split())
    num[v(x, y)] = r
    if x in nx: nx[x] += r
    else: nx[x] = r
    if y in ny: ny[y] += r
    else: ny[y] = r
    X.add(x)
    Yy.add(y)
ans = 0
Y = sorted([(ny[y], y) for y in Yy], reverse=True)
for x in X:
    for vv, y in Y:
        if v(x,y) in num:
            ans = max(ans, nx[x]+vv-num.pop(v(x, y)))
        else:
            ans = max(ans, nx[x]+vv)
            break
print(ans) 