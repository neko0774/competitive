import sys
sys.setrecursionlimit(1000)
cnt = 0
used = set()

def mergesort(ary):
  global cnt
  if len(ary)==1: return ary
  N = len(ary)//2
  f = mergesort(ary[:N])
  b = mergesort(ary[N:])
  res = []
  i, j = 0, 0
  while i<len(f) or j<len(b):
    if i<len(f) and j<len(b):
      cnt += 1
      print("?", f[i], b[j])
      q = int(input())
      #if q==-1:exit()
      if q:
        res.append(f[i])
        i+=1
      else:
        res.append(b[j])
        j+=1
    elif i<len(f):
      res.append(f[i])
      i+=1
    else:
      res.append(b[j])
      j+=1
  return res

def search(ary, x):
  ok = len(ary)
  ng = 0
  while ok-ng>0:
    m = (l+r)/2
    print("?", ary[m], x)
    if x>m:
      ok = m
    else:
      ng = m
  return ok


from collecions import heapq
N = int(input())
ary = [i+1 for i in range(N)]
ary = mergesort(ary)
h = heapq()
for i in range(N):
  print("+", ary[0], ary[-1])
  p = int(input())
  
  
