N, M = map(int, input().split())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]

def good(x):
  seller = 0
  buyer = 0
  for a in A:
    if a<=x: seller += 1
  for b in B:
    if x<=b: buyer += 1
  return seller>=buyer


ok = 10**9+3
ng = 0
while(abs(ok-ng)>1):
  m = (ok+ng)//2
  if good(m): ok = m
  else: ng = m
print(ok)