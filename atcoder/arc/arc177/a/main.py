M = [int(i) for i in input().split()]
N = int(input())
X = [int(i) for i in input().split()]

C = [1, 5, 10, 50, 100, 500]
for V, n in zip(C[::-1], M[::-1]):
  for i in range(N):
    need = X[i]//V
    if n>=need:
      X[i] %= V
      n -= need
    else:
      X[i] -= V*n
      n = 0
print("Yes" if sum(X)==0 else "No")