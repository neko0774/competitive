T = int(input())
for i in range(T):
  N = int(input())
  A = [int(i) for i in input().split()]
  B = [int(i) for i in input().split()]
  ans = 0
  d = abs(B[-1]-A[0])
  for a, b in zip(A, B[:-1]):
    ans += abs(b-a)
    if a<=B[-1]<=b or b<=B[-1]<=a:
      d = 0
    d = min(d, abs(B[-1]-a), abs(B[-1]-b))
  print(ans+d+1)
