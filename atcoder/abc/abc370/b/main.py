N = int(input())
A = [[int(i) - 1 for i in input().split()] for _ in range(N)]
atom = 0
for i in range(N):
  if atom > i: atom, i = i, atom
  atom = A[i][atom]
print(atom + 1)