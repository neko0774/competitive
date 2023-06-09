def main():
    N = int(input())
    A = [int(i) for i in input().split()]
    l = sum(A)
    B = [0 for _ in range(N+1)]
    V = [0 for _ in range(N+1)]
    V[0] = 1
    for n in range(N):
        if A[n]>V[n]:
            print(-1)
            return
        B[n] = V[n]-A[n]
        l -= A[n]
        V[n+1] = min(B[n]*2, l)
    if A[-1]>V[-1]:
        print(-1)
        return
    print(sum(V))
main()