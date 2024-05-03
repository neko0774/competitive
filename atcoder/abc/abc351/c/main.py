from collections import deque
N = int(input())
A = [int(i) for i in input().split()]
q = deque()
for a in A:
  q.append(a)
  while len(q)>=2 and q[-1]==q[-2]:
    q.pop()
    q[-1] += 1
print(len(q))