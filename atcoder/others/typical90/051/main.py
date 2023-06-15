N, K, P = map(int, input().split())
A = [int(i) for i in input().split()]

first_half = dict()
second_half = dict()
first_half[0] = 1
second_half[0] = 1
for a in A[:N//2]:
    memo = dict()
    for n, v in first_half:
        memo[n+a] = v
    first_half |= memo

for a in A[:N//2]:
    memo = dict()
    for n, v in first_half:
        memo[n+a] = v
    second_half |= memo

first = sorted([i for i in first_half.keys()])
second = sorted([i for i in second_half.keys()])