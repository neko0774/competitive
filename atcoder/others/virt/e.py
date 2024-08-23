N = int(input())
ops = [input() for _ in range(N)]

X = [0, 0]
p = [[0, 0], [0, 1], [1, 0], [1, 1]]


def calc(x):
  y = x
  cnt = [0, 0]
  cnt[x] += 1
  for i in range(N):
    op = min if ops[i] == 'AND' else max
    for nx in [0, 1]:
      ny = op(y, nx)
      

