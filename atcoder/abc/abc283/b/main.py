N = int(input())
A = [int(i) for i in input().split()]
Q = int(input())

for _ in range(Q):
    q = input()
    if q[0]=="1":
        _, k, x = map(int, q.split())
        A[k-1] = x
    else:
        _, k = map(int, q.split())
        print(A[k-1])