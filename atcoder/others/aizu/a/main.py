N = int(input())
cnt = 0
for i in range(N):
  s = input()
  if s=='A':
    cnt += 1
  else:
    cnt -= 1
  if cnt<0:
    print("NO")
    exit()
print("YES" if cnt==0 else "NO")