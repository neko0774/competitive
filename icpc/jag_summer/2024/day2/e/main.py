def expression(x):
  pass

def primary(x):
  pass

def number(x):
  pass

def number_sub(x):
  if len(x) == 1:
    return digit(x)
  return number_sub(x) + digit(x)
  

def digit(x):
  if x[0] != '0':
    return None
  return '0' + nonzero_digit(x[1:])

def nonzero_digit(x):
  if ord('1') <= ord(x) <= ord('9'):
    return x
  return None