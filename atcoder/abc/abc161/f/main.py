def sort_divisions(number):#約数列挙
    i = 2
    front, back = [],[number]
    while i*i <= number:
        if number%i==0:
            front.append(i)
            if i!=number//i: back.append(number//i)
        i+=1
    return front+back[::-1]


N = int(input())
fact = sort_divisions(N)
ans = set(sort_divisions(N-1))
for n in fact:
    NN = N
    while NN%n==0:
        NN /= n
    if NN%n==1: ans.add(n)
print(len(ans))