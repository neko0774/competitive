def main():
  S = [i for i in input()]

  N = len(S)
  dif = 0
  for i in range(N//2):
    if S[i]!=S[-1-i]:dif += 1
  
  if dif==0:
    ans = 25*(len(S)//2*2)
  elif dif==1:
    ans = 24*2+25*(len(S)-2)
  else:
    ans = 25*len(S)
  print(ans)

main()