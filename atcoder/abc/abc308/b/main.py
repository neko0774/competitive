N, M = map(int, input().split())
C = [i for i in input().split()]
D = [i for i in input().split()]
P = [int(i) for i in input().split()]
price = dict()
for i in range(M):
  price[D[i]] = P[i+1]
ans = 0
for c in C:
  if c in price: ans += price[c]
  else: ans += P[0]
print(ans)