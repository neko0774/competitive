def is_delete(S):
  H = len(S)
  W = len(S[0])
  #print(W)
  NS = [["."]*W for _ in range(H)]
  ret = 0
  for y in range(H):
    cnt = 0
    ls = ["", -1]
    for x in range(W):
      #print(cnt, ls, S[y][x])
      if ls[0]==S[y][x] and S[y][x]!='.':
        cnt += 1
      else:
        if cnt>=3:
          ret += cnt*int(ls[0])
          #print(cnt, ls[0], cnt*int(ls[0]), ret)
          for xx in range(ls[1], x):
            S[y][xx] = "."
        ls[0] = S[y][x]
        ls[1] = x
        cnt = 1
    if cnt>=3:
      ret += cnt*int(ls[0])
      for xx in range(ls[1], x+1):
        S[y][xx] = "."
  for x in range(W):
    ind = 0
    for y in range(H)[::-1]:
      ##if x==2: print(ind, S[y][x])
      if S[y][x]!='.': NS[y+ind][x]=S[y][x]
      else:
        ind += 1
  return NS, ret


while True:
  H = int(input())
  if H==0: exit()

  S = [[i for i in input().split()] for _ in range(H)]
  ans = 0
  while True:
    S, cnt = is_delete(S)
    ans += cnt
    if cnt==0: break
  print(ans)