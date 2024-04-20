def count(x):
  if x==0:
    return 61
  ret = 0
  while x%2==0:
    x //= 2
    ret += 1
  return ret
L, R = map(int, input().split())
ans = []
while R>L:
  c = count(L)
  for i in range(c+1)[::-1]:
    b = L//(2**i)
    if (b+1)*(2**i)<=R:
      ans.append([b*(2**i), (b+1)*(2**i)])
      L = (b+1)*(2**i)
      break
print(len(ans))
for a  in ans:
  print(*a)