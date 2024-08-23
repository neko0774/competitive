A, B, C = map(int, input().split())

if ((A < B or C < A) and B < C) or (C < B and C < A < B):
  print("Yes")
else:
  print("No")