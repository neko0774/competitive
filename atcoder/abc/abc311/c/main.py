N = int(input())
A = [int(i)-1 for i in input().split()]

count = [0]*N
for x in range(N):
  if count[x]: continue
  flag = 0
  while True:
    count[x]+=1
    x = A[x]
    if count[x]:
      flag = 1
      break
  if flag: break
visited = []
while True:
  visited.append(x+1)
  x = A[x]
  if x+1==visited[0]: break
print(len(visited))
print(*visited)