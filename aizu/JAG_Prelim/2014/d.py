def search(seen, change, string):
  if len(string)==len(S):
    return [string]
  ret = []
  i = len(string)
  print(change, string)

  if S[i] in change:
    string.append(S[i])
    seen.add(S[i])
    ret += search(seen, change, string)
  else:
    if not (S[i]+1) in seen or S[i]!=0:
      string.append(S[i]+1)
      seen.add(S[i]+1)
      change.add(S[i])
      ret += search(seen, change, string)
    else:
      string.append(S[i]+1)
      change.add(S[i])
      ret += search(seen, change, string)
      change.discard(S[i])
      string.append(S[i])
      ret += search(seen, change, string)
  return ret


def convert(S):
  ret = ""
  for s in S:
    ret += chr(s+ord('a'))
  return ret


while True:
  S = [ord(i)-ord('a') for i in input()]
  if S=='#': exit()
  ans = search(set(), set(), [])
  print(len(ans))
  if len(ans)<=10:
    for a in ans:
      print(convert(a))
  else:
    for a in ans[:5]:
      print(convert(a))
    for a in ans[-5:-1]:
      print(convert(a))