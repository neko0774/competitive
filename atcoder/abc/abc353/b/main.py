N, K = map(int, input().split())
A = [int(i) for i in input().split()]

ppl = 0
ans = 0
for a in A:
  if ppl+a>K:
    ans += 1
    ppl = a
  else:
    ppl += a
if ppl>0:
  ans += 1
print(ans)