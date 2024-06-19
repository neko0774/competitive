N = 20
S = []
S.append('b')
S.append('a')
for i in range(N):
  S.append(S[-1]+S[-2])
  #print(S[-1][1:]+'a')
print(S[-1])
exit()
print(S[-1])
ans = ''
memo = 0
for s in S[-1]:
  if s=='b':
    ans += str(memo-1)
    memo = 0
  else:
    memo += 1

print(ans)


memo = 0
ans2 = ''
for s in ans[1:]:
  if s == '0':
    ans2 += str(chr(memo-1+ord('x')))
    memo = 0
  else:
    memo += 1
    
print(ans2)