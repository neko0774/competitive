def countup():
  global i
  i+=1

def number(s):
  global i
  res=''
  while i<len(s) and '0'<=s[i]<='9':
    res+=s[i]
    i+=1
  return int(res)

def expr(s):
  global i
  res=term(s)
  while i<len(s):
    if s[i]=='+':
      i+=1
      res+=term(s)
      continue
    elif s[i]=='-':
      i+=1
      res-=term(s)
      continue
    return res
  return res

def term(s):
  global i
  res=factor(s)
  while i<len(s):
    if s[i]=='*':
      i+=1
      res*=factor(s)
      continue
    elif s[i]=='/':
      i+=1
      res2=factor(s)
      if res*res2>0:
        res=abs(res)//abs(res2)
      else:
        res=abs(res)//abs(res2)
        res=-res
      continue
    elif s[i]=='(' and '0'<=s[i]<='9':
      res*=factor(s)
      continue
    else:
      break
  return res

def factor(s):
  global i
  if s[i]=='(':
    i+=1
    res=expr(s)
    if s[i]==')':
      i+=1
    return res
  return number(s)


for _ in range(int(input())):
  s=input()[:-1]
  i=0
  print(expr(s))
