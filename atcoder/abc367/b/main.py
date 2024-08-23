X = [i for i in input()]
while X[-1] == '0' or X[-1] == '.':
  if X[-1] == '.':
    X.pop()
    break
  X.pop()
print("".join(X))