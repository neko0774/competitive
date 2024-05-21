def solve():
  a, b, c, d = map(int, input().split())
  if a>b:
    a,b = b, a
  if c>d:
    c,d = d, c
  #print(a, b, c, d)
  if (a<c<b and c<b<d) or (a<d<b and c<a<d):
    print("Yes")
  else:
    print("No")



T = int(input())
for _ in range(T):
  solve()