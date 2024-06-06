N, M = map(int, input().split())

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


S = sort_divisions(M)
for s in S[::-1]:
  if M-s*N>=0 and (M-s*N)%s==0:
    print(s)
    exit()
print(1)