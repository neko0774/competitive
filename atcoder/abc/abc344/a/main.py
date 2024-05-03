S = input()
ans = ''
flag = True
for s in S:
  if s == '|':
    flag = not flag
  if flag and s!='|':
    ans += s

print(ans)