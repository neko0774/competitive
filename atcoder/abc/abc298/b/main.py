N = int(input())
A = [[int(i) for i in input().split()] for _ in range(N)]
B = [[int(i) for i in input().split()] for _ in range(N)]

def rot(A):
    NA = [[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            NA[i][N-j-1] = A[j][i]
    return NA
def check(A, B):
    for i in range(N):
        for j in range(N):
            if A[j][i]==1 and B[j][i]!=1: return False
    return True


for _ in range(4):
    if check(A, B):
        print("Yes")
        exit()
    A = rot(A)
print("No")