S = input()
def is_parin(S):
  N = len(S)
  for i in range((N+1)//2):
    if S[i]!=S[-i-1]:
      return False
  return True

ans = 1
N = len(S)
for i in range(N):
  for j in range(i+2, N+1):
    if is_parin(S[i:j]):
      ans = max(ans, j-i)
print(ans)