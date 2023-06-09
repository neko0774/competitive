A, X, M = map(int, input().split())
def inv(A, M):
    



if A!=1: S = (pow(A, X, M)-1)*inv(A-1, M)%M
else: S = X%M
print(S)