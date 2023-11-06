from collections import Counter
N = int(input())
A = [int(i) for i in input().split()]
C = Counter(A)
print("Yes" if len(C)==1 else "No")
