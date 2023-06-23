from bisect import bisect_right as bl
while True:
  N, M = map(int, input().split())
  if N==M==0: exit()
  A = [int(i) for i in input().split()]

  A.sort()
  ans = 0
  #print(A)
  for n, a in enumerate(A):
    i = bl(A, M-a)
    #print(n, i, ans, A, M-a)
    if i==0:
      continue
    elif i==n+1:
      if i==1:
        continue
      else:
        ans = max(ans, a+A[i-2])
    else:
      ans = max(ans, a+A[i-1])
  print("NONE" if ans==0 else ans)