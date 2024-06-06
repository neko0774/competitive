N, L, R = map(int, input().split())
R += 1





def count(x):
  ret = 1
  cnt = 0
  while x%2==0:
    ret *= 2
    cnt+=1
    x //= 2
  return ret, cnt

ans = 0
while R-L>1:
  if L==0:
    x = R
    l = 1
    i = 0
    while x>=2:
      x //= 2
      l *= 2
      i += 1
  else:
    l, i = count(L)
    while l*2>=R:
      l //= 2
      i -= 1
  j = L//l
  #print(L, R, l)
  print("?", i, j)
  S = int(input())
  ans += S
  ans %= 100
  L = l*(j+1)

print("!", ans)
exit()