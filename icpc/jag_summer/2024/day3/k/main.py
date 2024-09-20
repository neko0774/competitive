class UnionFind:
  def __init__(self, N):
    self.root = list(range(N + 1))
    self.size = [1] * (N + 1)
    self.N = N

  def find(self, x):
    root = self.root
    lis = []
    while root[x] != x:
      lis.append(x)
      x = root[x]
    for l in lis:
      root[l] = x
    return x

  def merge(self, x, y):
    root, size = self.root, self.size
    x = self.find(x)
    y = self.find(y)
    if size[x] < size[y]:
      x, y = y, x
    #集合のmerge部分 
    if len(not_same[x]) > len(not_same[y]):
      not_same[y] |= not_same[x]
      not_same[x] = not_same[y]
    else:
      not_same[x] |= not_same[y]
      not_same[y] = not_same[x]

    root[y] = root[x]
    size[y] += size[x]
  
  def is_same(self, x, y):
    return self.find(x) == self.find(y)
  

N, M = map(int, input().split())
A = [-1 for _ in range(N + 5)]
i = 0
uf = UnionFind(N * 2 + 3)
not_same = [set() for _ in range(N * 2 + 3)]
for _ in range(M):
  q = input()
  if q[0] == '1':
    _, x, y = map(int, q.split())
    x -= 1
    y -= 1
    if A[x] == -1 and A[y] == -1:
      A[x] = i
      A[y] = i
      i += 1
    elif A[x] == -1:
      A[x] = A[y]
    elif A[y] == -1:
      A[y] = A[x]
    else:
      uf.merge(A[x], A[y])

  elif q[0] == '2':
    _, x, y = map(int, q.split())
    x -= 1
    y -= 1
    if A[x] == -1:
      A[x] = i
      i += 1
    if A[y] == -1:
      A[y] = i
      i += 1
    ax = uf.find(A[x])
    ay = uf.find(A[y])
    not_same[ax].add(ay)
    not_same[ay].add(ax)

  elif q[0] == '3':
    _, x = map(int, q.split())
    x -= 1
    if A[x] == -1: continue
    ax = uf.find(A[x])
    A[x] = i
    not_same[ax].add(i)
    #not_same[A[x]] = not_same[ax]
    i += 1
    
  else:
    _, x, y = map(int, q.split())
    x -= 1
    y -= 1
    ax = uf.find(A[x])
    ay = uf.find(A[y])
    #print(ax, ay, A[x], A[y], x, y)
    #print(not_same, A, uf.root)
    if uf.is_same(A[x], A[y]):
      print("Yes")
    elif (A[y] != -1 and ay != -1 and ax in not_same[ay]) or (A[x] != -1 and ax != -1 and ay in not_same[ax]):
      print("No")
    else:
      print("Unknown")