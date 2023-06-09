N, M = map(int, input().split())
B = [int(i) for i in input().split()]
C = [int(i) for i in input().split()]

B.sort()
CC = sorted([[C[i], i] for i in range(M)], reverse=True)
people = 0
price = 0
ans = [0]*M
for i in range(N)[::-1]:
    if price>(B[i]+CC[0][0])*(people+1):
        ans[CC[0][1]] = price
        break
    price = (B[i]+CC[0][0])*(people+1)
    people += 1
if ans[CC[0][1]]==0: ans[CC[0][1]] = price


i = N-people
for c, n in CC[1:]:
    price = (B[i]+c)*people
    #print(n, c, people, B[i], price)
    while i+1<N and price<(B[i+1]+c)*(people-1):
        #print(c, people, B[i], price)
        people -= 1
        i += 1
        price = (B[i]+c)*(people)

    ii = i    
    npeople = people
    while ii+1<N and B[i]==B[i+1]:
        ii += 1
        npeople -= 1
        if price<(B[ii]+c)*npeople:
            price = (B[ii]+c)*npeople
            break

    ans[n] = price
print(*ans)