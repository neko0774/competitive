def sovle():
  N = int(input())
  if N==0:
    exit()
  A = [int(i) for i in input().split()]
  A.sort()
  ans = 1
  memo = 0
  l = -100
  for a in A:
    if a==l+1:
      memo += 1
    else:
      ans = max(ans, memo)
      memo = 1
    #print(a, l, ans, memo)
    l = a
  ans = max(ans, memo)
  print(ans)


while True:
  sovle()