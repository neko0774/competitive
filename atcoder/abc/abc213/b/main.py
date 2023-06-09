N = int(input())
A = [int(i) for i in input().split()]
B = [[A[i], i+1] for i in range(N)]
B.sort()
print(B[-2][-1])