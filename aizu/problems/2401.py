import itertools as it
def equation():
  for ite in it.products([0, 1], len(cnt)):
    f = formula()
    consume('+')
    b = formula()
    if f!=b: return "No"
  return "Yes"

def formula():
  global cnt



while True:
  S = input()
  if S=='#': exit()
  cnt = set()
  begin = 0
  for s in S:
    if s.islower(): cnt.add(s)
  convert = dict([i:j for j, i in enumerate(sorted(cnt))])
  and