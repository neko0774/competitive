N = int(input())
A = [int(i) for i in input().split()]
for a in A:
  v = Node(a)

Q = int(input())
query = []
num = A[:]
for _ in range(Q):
  q = input()
  if q[0] == '1':
    _, x, y = map(int, q.split())
    query.append([1, x, y])
    num.append(y)
  else:
    _, x = map(int, q.split())
    query.append([2, x])

conv = dict()
iconv = dict()
num = set(num)
i = 0
for n in num:
  conv[i] = n
  iconv[n] = i
  i += 1

