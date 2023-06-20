N = int(input())
A = [int(i) for i in input().split()]
time = [0]
for i in range(1, N-1, 2):
    time.append(time[-1]+A[i+1]-A[i])
Q = int(input())

from bisect import bisect_left as bl

for _ in range(Q):
    l, r = map(int, input().split())
    l_id = bl(A, l)
    r_id = bl(A, r)

    ans = time[r_id//2]-time[l_id//2]
    #print(l_id, r_id, ans)
    if l_id%2==0:
        #starting sleeping time is A[l_id]
        ans += A[l_id]-l
    else:
        pass
        #staring sleeping time is l
    
    if r_id%2==0:
        ans -= A[r_id]-r
        #end sleep at A[r_id-1]
    else:
        #end sleep at r
        pass
    print(ans)