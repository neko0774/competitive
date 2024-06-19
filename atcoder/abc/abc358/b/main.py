N, A = map(int, input().split())
T = [int(i) for i in input().split()]

time = 0
wait = 0
for a in T:
  if a>=time:
    time = a+A
  else:
    time += A
  print(time)