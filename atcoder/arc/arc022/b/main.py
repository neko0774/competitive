N = int(input())
A = [int(i) for i in input().split()]

l = 0
ans = 0
colour = set()
for r in range(N):
    while l<=r and A[r] in colour:
        colour.discard(A[l])
        l += 1
    colour.add(A[r])
    ans = max(ans, len(colour))
print(ans)