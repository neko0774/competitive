from random import randint
N = 7 
V = []
for _ in range(N):
    x, y, z = randint(1, 50), randint(1, 50), randint(1, 50)
    V.append([max(x,y,z), x+y+z-max(x,y,z)-min(x,y,z), min(x,y,z), x*y*z])

print(7)
for i in V:
    print(*i[:-1])
