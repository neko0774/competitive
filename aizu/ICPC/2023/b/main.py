while True:
  N, M, P, Q = map(int, input().split())
  if N==0:exit()
  P -= 1
  Q -= 1
  X = [int(i)-1 for i in input().split()]
  from_p = [-1]*(M+1)
  from_q = [-1]*(M+1)
  from_p[0] = P
  from_q[-1] = Q
  for m in range(1, M+1):
    if X[m-1]==from_p[m-1]:
      from_p[m] = from_p[m-1]+1
    elif X[m-1]+1==from_p[m-1]:
      from_p[m] = from_p[m-1]-1
    else:
      from_p[m] = from_p[m-1]
    
  for m in range(1, M+1)[::-1]:
    if X[m-1]==from_q[m]:
      from_q[m-1] = from_q[m]+1
    elif X[m-1]+1==from_q[m]:
      from_q[m-1] = from_q[m]-1
    else:
      from_q[m-1] = from_q[m]
  if from_p[-1]==Q:
    print("OK")
  else:
    flag = 1
    for i in range(M+1):
      if (from_p[i]==from_q[i]+1 or from_p[i]==from_q[i]-1):
        print(min(from_p[i], from_q[i])+1, i)
        flag = 0
        break
    if flag: print("NG")
  #print(from_p)
  #print(from_q)
