N, A, X, Y = map(int, input().split())
import sys
sys.setrecursionlimit(10**6)

memo = dict()
memo[0] = 0
def f(x):
  if x in memo: return memo[x]
  v = Y*6/5
  for i in range(2, 7):
    v += f(x//i)/5
  memo[x] = min(X+f(x//A), v)
  return memo[x]

print(f(N))