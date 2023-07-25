N = int(input())
S = [i for i in input()]
check = {'A', "B", "C"}
for n, s in enumerate(S):
  check.discard(s)
  if len(check)==0:
    print(n+1)
    exit()