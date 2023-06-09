def factorization(x):
    i = 2
    ans = []
    while i**2 <= x:
        e = 0
        while x%i == 0:
            e += 1
            x //= i
        if e>0:
            ans.append([i, e])
        i += 1
    if x!=1: ans.append([x, 1])
    return ans

from collections import defaultdict
def main():
    N = int(input())
    count = defaultdict(int)

    for NN in range(1, N+1):
        for num, cnt in factorization(NN):
            count[num] += cnt
    
    '''
    a^74
    a^3*b^25
    a^5*b^15
    a^3*b^5*c^5
    '''

    ans = 0
    l3, l5, l15, l25 = 0,0,0,0
    for b in count.values():
        if b>=74: ans += 1
        if b>=24: l25+=1
        if b>=14: l15+=1
        if b>=4: l5+=1
        if b>=2: l3+=1
    
    ans += l25*(l3-1)+l15*(l5-1)+l5*(l5-1)*(l3-2)//2
    print(ans)
main()