N = int(input())

def sort_divisions(number):#約数列挙
    i = 2
    front, back = [],[number]
    while i*i <= number:
        if number%i==0:
            front.append(i)
            if i!=number//i: back.append(number//i)
        i+=1
    return front+back[::-1]

ans = 10**15
for n in sort_divisions(N):
    ans = min(ans, n+N//n-2)
print(ans)