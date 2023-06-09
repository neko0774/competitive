from bisect import bisect_left as bl
N = int(input())
C = [int(input()) for _ in range(N)]

lis = [10**18]*N
for c in C:
    lis[bl(lis, c)] = c
print(bl(lis, 10**18))
