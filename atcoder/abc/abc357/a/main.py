N, M = map(int, input().split())
H = [int(i) for i in input().split()]
for i in range(N):
  M -= H[i]
  if M<0:
    print(i)
    exit()
print(N)
