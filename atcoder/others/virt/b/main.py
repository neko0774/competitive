N = int(input())
A = [int(i) for i in input().split()]

def count(x):
    ret = 0
    while x%2==0:
        ret += 1
        x //= 2
    return ret

print(sum([count(i) for i in A]))