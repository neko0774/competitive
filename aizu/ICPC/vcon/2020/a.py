while True:
  N, M = map(int, input().split())
  if N==M==0: exit()
  A = [int(i) for i in input().split()]
  B = [int(i) for i in input().split()]

  cnt = [0 for _ in range(10)]
  for a in A:
    for b in B:
      n = a*b
      while n:
        cnt[n%10]+=1
        n//=10
  print(*cnt)