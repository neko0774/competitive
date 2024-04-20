N = int(input())
pos = []
for _ in range(N):
  x, y = map(int, input().split())
  pos.append([x, y])

M = int(input())
op = []
for _ in range(M):
  op.append(input())

querys = []
Q = int(input())
for i in range(Q):
  a, b = map(int, input().split())
  querys.append([a, b-1, i])
querys.sort()

ans = [[-1, -1] for _ in range(Q)]
is_switch = False
x_sign = 1
y_sign = 1
x_buffer = 0
y_buffer = 0
cur = 0

while cur<Q and querys[cur][0]==0:
  X = pos[querys[cur][1]][0]
  Y = pos[querys[cur][1]][1]
  ans[querys[cur][-1]] = [X, Y]
  cur += 1

for i in range(M):

  if (op[i][0]=="1" and not is_switch) or (op[i][0]=="2" and is_switch):
    is_switch = not is_switch
    y_sign *= -1

  elif (op[i][0]=="1" and is_switch) or (op[i][0]=="2" and not is_switch):
    is_switch = not is_switch
    x_sign *= -1

  elif (op[i][0]=="3" and not is_switch) or (op[i][0]=="4" and is_switch):
    _, p = map(int, op[i].split())
    x_buffer += x_sign*2*p
    x_sign *= -1

  else:
    _, p = map(int, op[i].split())
    y_buffer += y_sign*2*p
    y_sign *= -1
  while cur<Q and querys[cur][0] == i+1:
    Y = y_buffer+y_sign*pos[querys[cur][1]][1]
    X = x_buffer+x_sign*pos[querys[cur][1]][0]
    print(cur, x_sign, x_buffer)
    if is_switch:
      ans[querys[cur][-1]] = [Y, X]
    else:
      ans[querys[cur][-1]] = [X, Y]
    cur+= 1

print(*ans, sep='\n')