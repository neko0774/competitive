R, G, B = map(int, input().split())
C = input()
if C[0] == 'B':
  print(min(R, G))
elif C[0] == 'G':
  print(min(R, B))
else:
  print(min(B, G))