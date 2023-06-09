def sort_divisions(number)->list:#約数列挙
    if number==1: return [1]
    i = 2
    front, back = [1],[number]
    while i*i <= number:
        if number%i==0:
            front.append(i)
            if i!=number//i: back.append(number//i)
        i+=1
    return front+back[::-1]

N = int(input())
ans = 0
count = [0]*(N+1)
for n in range(1, N+1):
    count[n] = len(sort_divisions(n))
for n in range(1, N+1):
    ans += count[n]*count[N-n]
print(ans)