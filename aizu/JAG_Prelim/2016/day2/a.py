while True:
  RZ, WZ,  C, R = map(int, input().split())
  if RZ==WZ==C==R==0: exit()

  for r in range(10**5):
    conc = (RZ+r*R-C*WZ)
    #print(conc)
    if conc>=0:
      print(r)
      break