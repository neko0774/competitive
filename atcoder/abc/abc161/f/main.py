def sort_divisions(number)->list:#約数列挙
	if number==1: return []
	i = 2
	front, back = [],[number]
	while i*i <= number:
		if number%i==0:
			front.append(i)
			if i!=number//i: back.append(number//i)
		i+=1
	return front+back[::-1]

N = int(input())
ans = set(sort_divisions(N-1))
L = sort_divisions(N)

def is_ok(N, k):
  while N%k==0:
    N /= k
  return N%k==1

for l in L:
  if is_ok(N, l): ans.add(l)
print(len(ans))