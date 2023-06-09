def main():
    N = int(input())

    A = [int(i) for i in input().split()]
    B = [int(i) for i in input().split()]

    AS, BS = [0]*N, [0]*N     
    AA = set()
    BB = set()
    to_change = dict() 
    index = 0
    for i in range(N):
        if not A[i] in to_change:
            to_change[A[i]] = index
            index += 1
        AA.add(A[i])
        BB.add(B[i])
        AS[i] = len(AA)
        BS[i] = len(BB)
    A = [to_change[i] for i in A]
    B = [to_change[i] if i in to_change else 10**6 for i in B]
    for i in range(1, len(B)):
        B[i] = max(B[i-1], B[i])
        A[i] = max(A[i-1], A[i])
    Q= int(input())
    for _ in range(Q):
        x,y = map(int, input().split())
        x -= 1
        y -= 1
        if AS[x]==BS[y] and A[x] == B[y]:
            print("Yes")
        else:
            print("No")
main()