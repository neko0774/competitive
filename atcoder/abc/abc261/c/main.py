N = int(input())
count = dict()
for _ in range(N):
  S = input()
  if S in count:
    print(S+"("+str(count[S])+")")
  else:
    print(S)
    count[S] = 0
  count[S] += 1