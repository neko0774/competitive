N = int(input())
A = [int(i) for i in input().split()]

def calc(low, high):
  p = 0
  m = 0
  for a in A:
    if a==low or a==high: continue
    elif a>high: p += a-high
    else: m+=low-a
  
  return max(p, m)


v = sum(A)
ave = v//N
if v%N==0: print(min(calc(ave-1, ave), calc(ave,ave+1)))
else: print(calc(ave, ave+1))
