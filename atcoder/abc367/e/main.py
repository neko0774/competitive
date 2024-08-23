N, K = map(int, input().split())
X = [int(i) - 1 for i in input().split()]
A = [int(i) for i in input().split()]
ans = A[:]


lg = K.bit_length() + 2
nex = [[0 for _ in range(lg)] for _ in range(N)]
for i in range(N): nex[i][0] = X[i]

for l in range(1, lg):
  for i in range(N):
    nex[i][l] = nex[nex[i][l - 1]][l - 1]


c = 0
res = [i for i in range(N)]
while K:
  if K & 1:
    for i in range(N):
      res[i] = nex[res[i]][c]
  K >>= 1
  c += 1
ans = [A[res[i]] for i in range(N)]
print(*ans)