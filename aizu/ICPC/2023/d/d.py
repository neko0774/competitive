S = "oxxxoxxxxxxxxxxxxxxxxxxxxxxxxxxxxxoxxxxxxxxxxoxxxxxxxoxxxxoxxxxxooxxxxxxxoxxoxxxxxxxxxxxxxxxxxo"
ans = []
for n, s in enumerate(S):
  if s=="o": ans.append(n)
print(ans)