N = int(input())
G1 = []
G2 = []
X1 = []
X2 = []
Y1 = []
Y2 = []

for _ in range(N):
  x, y = map(int, input().split())
  if abs(x-y)%2==0:
    u = x+y
    v = -x+y
    G1.append([u, v])
    X1.append(u)
    Y1.append(v)
  else:
    u = x+y
    v = -x+y
    G2.append([u, v])
    X2.append(u)
    Y2.append(v)

X1.sort()
X2.sort()
Y1.sort()
Y2.sort()
def calc(A):
  ret = 0
  v = sum(A)
  N = len(A)
  for i in range(N-1):
    v -= A[-i-1]
    ret += A[-i-1]*(N-i-1)-v
  return ret
ans= 0
for x in [X1, X2, Y1, Y2]:
  ans += calc(x)
print(ans//2)