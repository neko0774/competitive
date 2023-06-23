def calc(x, y):
  if x==1 and y==1: return ("R", 1)
  if x==1 and y==0: return ("L", 0)
  if x==0 and y==1: return ("L", 1)
  if x==0 and y==0: return ("R", 0)


while True:
  N, i, j = map(int, input().split())
  if N==i==j==0: exit()
  ans = ""
  rev = 0
  h = 2**N-i
  h = bin(h)[2:]
  h = h+"0"*(N-len(h))
  j = bin(j-1)[2:]
  j = "0"*(N-len(j))+j
  print(h)
  print(j)
  for n in range(N):
    print(rev^int(h[n]), int(j[n]))
    let, r = calc(rev^int(h[n]), int(j[n]))
    ans += let
    if r: rev ^= r
  print(ans)
