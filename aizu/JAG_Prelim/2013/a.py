while True:
  S = input()
  if S=="#": exit()

  small = []
  big = []
  num = [] 
  for s in S:
    if ord("a")<=ord(s)<=ord("z"): small.append(s)
    elif ord("A")<=ord(s)<=ord("Z"): big.append(s)
    elif s.isdigit(): num.append(s)

  small.sort()
  big.sort()
  num.sort()
  ans = "".join(small)+"".join(big)+"".join(num)
  print(ans)