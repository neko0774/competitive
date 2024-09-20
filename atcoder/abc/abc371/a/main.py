a, b, c = input().split()
if (a == '<' and c == '<') or (a == '>' and c == '>'):
  print('B')
elif (a == '<' and b == '>') or (a == '>' and b == '<'):
  print('A')
else:
  print('C')
