N = int(input())
A = [int(i)-1 for i in input().split()]
not_call = set(range(N))
for a in range(N):
    if a in not_call:
        not_call.discard(A[a])
print(len(not_call))
print(*[i+1 for i in sorted(not_call)])