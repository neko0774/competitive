import itertools as it

def main():
    N = int(input())
    A = [_ for _ in range(N)]
    X = [[] for _ in range(N)]
    for i in range(N):
        A[i] = int(input())
        for j in range(A[i]):
            X[i].append([int(i) for i in input().split()])
    ans = 0
    for iter in it.product([0, 1], repeat=N):
        flag = True
        for i in range(N):
            if iter[i]==1:
                for x, y in X[i]:
                    if not iter[x-1]==y:
                        flag = False
                        break
                if not flag: break
        if flag: ans = max(ans, sum(iter))
    print(ans)
                


main()