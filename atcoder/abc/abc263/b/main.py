N = int(input())
P = [-1] + [int(i)-1 for i in input().split()]

ans = 0
x = -1
while x!=0:
  x = P[x]
  ans += 1
print(ans)