from random import randint as rd

N = rd(1, 100)
A = [rd(1, 10) for _ in range(N)]
print(N)
print(*A)
