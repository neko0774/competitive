S = input()
cnt = 0
for s in S:
  if s.islower():
    cnt+=1

if cnt*2>len(S):
  print(S.lower())
else:
  print(S.upper())