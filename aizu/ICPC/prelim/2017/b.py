while True:
  A = [i for i in input()]
  if A==["."]: exit()
  B = [i for i in input()]
  cnt = 0
  AA = len(A)
  ia = 0
  BB = len(B)
  ib = 0
  number = 0
  while True:
    mA = ""
    a_consumed = 0
    if ia<AA:
      a_consumed = 1
    while ia<AA and A[ia]!='"':
      mA += A[ia]
      ia += 1

    mB = "" 
    b_consumed = 0
    if ib<BB:
      b_consumed = 1
    while ib<BB and B[ib]!='"':
      mB += B[ib]
      ib += 1
    number += 1 
    if mA!=mB and number%2==0:cnt += 1
    elif mA!=mB: cnt += 2
    elif a_consumed!=b_consumed: cnt += 2
    if ib>=BB and ia>=AA: break
    ia += 1
    ib += 1
  if cnt==0:
    print("IDENTICAL")
  elif cnt==1:
    print("CLOSE")
  else:
    print("DIFFERENT")