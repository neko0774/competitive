N = int(input())
user = []
T = 0
for _ in range(N):
  s, c = input().split()
  T  += int(c)
  user.append(s)
user.sort()
print(user[T%N])