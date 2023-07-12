while True:
  N = int(input())
  if N==0: exit() 
  print(max([int(i) for i in input().split()]))