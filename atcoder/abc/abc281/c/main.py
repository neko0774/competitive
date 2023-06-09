def main():
    N, T = map(int, input().split())
    A = [int(i) for i in input().split()]

    T %= sum(A)
    for n,a in enumerate(A):
        if T-a>0:
            T -= a
        else:
            print(n+1, T)
            return



main()