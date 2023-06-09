def solve(a, x, m):
    ret = 0
    for i in range(x):
        ret += a**i
        ret %= m
    return ret


def ss(A, X, M):
    if modinv(A-1, M)==None:
        print(A-1, M)
        return None
    elif A!=1: S = (pow(A, X, M)-1)*modinv(A-1, M)%M
    else: S = X%M
    return S


def extended_gcd(a, b):
    """returns gcd(a, b), s, r s.t. a * s + b * r == gcd(a, b)"""
    s, old_s = 0, 1
    r, old_r = b, a
    while r:
        q = old_r // r
        old_r, r = r, old_r - q * r
        old_s, s = s, old_s - q * s
    return old_r, old_s, (old_r - old_s * a) // b if b else 0

from math import gcd
def modinv(a, m):
    """returns the modular inverse of a w.r.t. to m, works when a and m are coprime"""
    grt = gcd(a, m)
    a //= grt
    m //= grt
    g, x, _ = extended_gcd(a % m, m)
    return x % m if g == 1 else None


from random import randint
for _ in range(100):
    a, x, m = randint(1, 100), randint(1, 100), randint(1, 100)
    if solve(a, x, m)!=ss(a, x, m):
        print(a, x, m, solve(a, x, m), ss(a, x, m))

