N = int(input())
A = [int(i) for i in input().split()]
M = int(input())
B = [int(i) for i in input().split()]
L = int(input())
C = [int(i) for i in input().split()]

Q = int(input())
X = [int(i) for i in input().split()]
ok = set()
for a in A:
  for b in B:
    for c in C:
      ok.add(a+b+c)
  
for x in X:
  if x in ok:
    print("Yes")
  else:
    print("No")