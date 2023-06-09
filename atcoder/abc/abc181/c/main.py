N = int(input())
points = []
for _ in range(N):
    x, y = map(int, input().split())
    points.append([x, y])

def is_same(A, B, C):
    if A[0]==B[0]==C[0]: return 1
    elif A[0]==B[0] or A[0]==C[0] or B[0]==C[0]: return 0
    slope = (B[1]-A[1])/(B[0]-A[0])
    if C[1]-A[1]==slope*(C[0]-A[0]): return 1
    return 0
for i in range(N):
    for j in range(i+1, N):
        for z in range(j+1, N):
            if is_same(points[i], points[j], points[z]):
                print("Yes")
                exit()
print("No")