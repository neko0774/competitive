import math 
def main():
    N, n, m = map(int, input().split())
    A = [int(i) for i in input().split()]

    def is_ok(x):
        cnt = 0
        for a in A:
            if a<x:
                cnt -= math.ceil((x-a)/n)
            else:
                cnt += (a-x)//m
        return cnt>=0

    l = 0
    r = 10**12
    while abs(r-l)>1:
        mid = (r+l)//2
        if is_ok(mid):
            l = mid
        else:
            r = mid
    print(l)
main()