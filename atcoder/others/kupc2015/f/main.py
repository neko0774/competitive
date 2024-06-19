def eval(S):
  ans = []
  for s in S:
    if s.isdigit():
      ans.append(s)
    else:
      f = ans.pop()
      lf = ans.pop()
      if s=='-':
        f, lf = lf, f
      ans.append(lf+f+s)
  return ans
S = input()
print("".join(eval(S)))
