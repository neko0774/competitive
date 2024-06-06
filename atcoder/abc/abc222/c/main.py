N, M = map(int, input().split())
A = [[i for i in input()] for _ in range(2*N)]
count = [[10000, i] for i in range(2*N)]
def battle(x, y):
  if (x=='G' and y=='C') or (x=='C' and y=='P') or (x=='P' and y=='G'):
    return 1
  if (y=='G' and x=='C') or (y=='C' and x=='P') or (y=='P' and x=='G'):
    return -1
  return 0


for i in range(M):
  nex = []
  for j in range(N):
    if battle(A[count[2*j][1]][i], A[count[2*j+1][1]][i])==1:
      count[2*j][0] -= 1
    elif battle(A[count[2*j][1]][i], A[count[2*j+1][1]][i])==-1:
      count[2*j+1][0] -= 1
    nex.append(count[2*j])
    nex.append(count[2*j+1])
  nex.sort()
  count = nex[:]
for _, i in count:
  print(i+1)