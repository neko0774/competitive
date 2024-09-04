N = int(input())
L, R = map(int, input().split())
LL = [L]
RR = [R]
T = [[L, R]]
if N == 1 and L <= 0 <= R:
  print("Yes")
  print(0)
  exit()

for i in range(N - 1):
  l, r = map(int, input().split())
  L += l
  R += r
  LL.append(l)
  RR.append(r)
  T.append([L, R])




if L <= 0 <= R:
  print("Yes")
  ans = []
  cv = 0
  for i in range(N - 1)[::-1]:
    nv = max(cv - RR[i + 1], T[i][0])  
    ans.append(- nv + cv)
    cv = nv
  ans = [nv] + ans[::-1]
  assert(sum(ans) == 0)
  for i in range(N):
    assert(LL[i] <= ans[i] <= RR[i])
  print(*ans)
else:
  print("No")