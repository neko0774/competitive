mod = 998244353
def solve():
  N = int(input())
  S = [s for s in input()]
  ans = 0
  for i in range((N+1)//2):
    ans = (ans*26+ord(S[i])-ord('A'))
    ans %= mod
  if S[:N//2][::-1]<=S[-(N//2):]:
    print((ans+1)%mod)
  else:
    print(ans)
  
T = int(input())
for i in range(T):
  solve()