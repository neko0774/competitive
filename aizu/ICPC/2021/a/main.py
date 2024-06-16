
def ok(A):
  cnt = 0
  for a in A:
    if a==0: cnt+=1
  return cnt!=3

while True:
  A = [int(i) for i in input().split()]
  if max(A)==0:exit()

  while ok(A):
    mv = 1000
    first = 1
    for a in A:
      if a!=0: mv = min(mv, a)
    for i in range(4):
      if A[i]==mv and first:
        first = 0
        continue
      A[i] = max(0, A[i]-mv)
  print(max(A))
