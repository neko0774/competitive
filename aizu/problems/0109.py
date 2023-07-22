#expr = add
#add = mult[+|- mult]*
#mult = blk[*|/ blk]*
#blk = (add)|num
import sys
sys.setrecursionlimit(10**7)
def expr():
  return add()

def add():
  ret = mult()
  while begin<len(S) and S[begin] in ['+', '-']:
    if S[begin]=='+':
      consume('+')
      ret += mult()
    else:
      consume('-')
      ret -= mult()
  return ret

def mult():
  ret = blk()
  while begin<len(S) and S[begin] in ['*', '/']:
    if S[begin]=='/':
      consume('/')
      #print(ret, begin)
      if ret<0:
        ret = -(abs(ret)//blk())
      else:
        ret //= blk()
    else:
      consume('*')
      ret *= blk()
  return ret

def blk():
  if S[begin]=='(':
    consume('(')
    ret = add()
    consume(')')
    return ret
  return num()

def num():
  global begin
  ret = ""
  while begin<len(S) and S[begin].isdigit():
    ret += S[begin]
    begin += 1
  return int(ret)

def consume(s)->None:
  global begin
  assert s==S[begin]
  begin += 1

N = int(input())
ans = []
for _ in range(N):
  S = input()[:-1]
  begin = 0
  print(expr())