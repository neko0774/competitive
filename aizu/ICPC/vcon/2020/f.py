while True:
  N = int(input())
  if N==0: exit()
  org = []
  for _ in range(N):
    pos = [0]*6
    for i in range(5):
      s = input()
      if i==1:
        pos[-2] = conv(s[1])
        pos[-1] = conv(s[3])
      pos[i] = conv(s[2])
    org.append(pos)

  ans = [[0]*N for _ in range(N)]
  for i in range(N):
    for j in range(i, N):
      cnt = 0
      pos = deque(org[i][:4])
      L = org[i][-2]
      R = ord[i][-1]
      for c in range(6):



    