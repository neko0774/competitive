from random import randint as rd
N = rd(3, 6) * 2
A = "".join(['(' if rd(0, 1) == 0 else ')' for _ in range(N)])
print(N)
print(A)