from collections import deque
class UnionFind:
	def __init__(self, N):
		self.root = list(range(N+1))
		self.size = [1]*(N+1)
		self.N = N
		self.group_size = N
 
	def find_root(self, x):
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
		x = self.find_root(x)
		y = self.find_root(y)
		if x == y:
			return
		self.group_size -= 1
		if size[x] < size[y]:
			x, y = y, x
		root[y] = root[x]
		size[y] += size[x]
	
	def is_same(self, x, y):
		return self.find_root(x)==self.find_root(y)

	def group_size(self):
		return self.group_size

	def groups(self):
		G = [[] for _ in range(self.N)]
		for i in range(self.N):
			G[self.find_root(i)].append(i)
		return [i for i in G if i]

N, K = map(int, input().split())
if K==1:
  ans = []
  for i in range(1, N+1):
    print("?", i)
    ans.append(int(input()))
  print(*ans)
  exit()

uf = UnionFind(N)

ask = deque([i for i in range(1, K+1)])
zero = []
one = []
lst = -1
for i in range(K-1, N):
  print("?", *ask)
  NN = int(input())
  if NN==0:
    zero.append(i+1)
    lst = 0
  else:
    one.append(i+1)
    lst = 1
  ask.pop()
  ask.append(i+2)
  #print(zero, one, lst)
ask[-1] -= 1
for i in range(K-1)[::-1]:
  v = ask.pop()
  ask.appendleft(v)
  ask[-1]+=1
  print("?", *ask)
  NN = int(input())
  if NN==lst:
    if lst!=0:
      zero.append(i+1)
    else:
      one.append(i+1)
  else:
    if lst==0:
      zero.append(i+1)
    else:
      one.append(i+1)
  #print(zero, one)
  lst = NN

for n in zero[1:]:
  uf.merge(zero[0]-1, n-1)
for n in one[1:]:
  uf.merge(one[0]-1, n-1)
def const(e):
  ret = [e]
  for i in range(1, N):
    if uf.is_same(0, i):
      ret.append(e)
    else:
      ret.append(1-e)
  cnt = 0
  for a in ask:
    cnt += ret[a-1]
  #print(ret, cnt)
  if cnt%2==NN:
    print(ret)
#print(ask, NN)
ans = const(1)
ans = const(0)