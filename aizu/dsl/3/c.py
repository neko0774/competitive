N, Q = map(int, input().split())
A = [int(i) for i in input().split()]
X = [int(i) for i in input().split()]

def solve(x):
    cnt = 0
    l = 0
    num = 0
    for r in range(N):
        num += A[r]
        while num>x and r>=l:
            num -= A[l]
            l += 1
        cnt += r-l+1
    #print(l, r, cnt)
    return cnt

for x in X:
    print(solve(x))