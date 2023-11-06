from collections import defaultdict
import sys
sys.setrecursionlimit=10**7
N = int(input())
A = [int(i) for i in input().split()]

count = [[0, 0] for _ in range(2*N+5)]

def memo(x):
  if count[x][0]==0: return 0, count[x][1]
  to, cnt = memo(count[x][0])
  count[x][0] = to
  count[x][1] += cnt
  return to, count[x][1]


for i, a in enumerate(A):
  i = i+1
  count[i*2][0] = a
  count[i*2][1] = 1
  count[i*2+1][0] = a
  count[i*2+1][1] = 1

#0 -> 1, 2
#2 -> 5, 6
#4 -> 9, 10
#1 -> 3, 4
for k in range(1, 2*N+2):
  to, cnt = memo(k)
  print(cnt)
