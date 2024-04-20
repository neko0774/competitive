S = input()
T = [i for i in input()]
p = 0
for s in S:
  if p==3:
    print("Yes")
    exit()
  if s.upper()==T[p]:
    p+=1

if p==3 or (p==2 and T[p]=='X'):
  print("Yes")
  exit()
else:
  print("No")