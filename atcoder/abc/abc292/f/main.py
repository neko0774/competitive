A, B = map(int, input().split())
from math import pi, acos, cos
ok = 0
bad = 2000
if A>B:
	A, B = B, A

def is_ok(l):
	theta = acos(A/l) if A/l<1 else 0
	if not 0<=theta<=pi/6: return False
	return l*cos(pi/6-theta)<=B

for i in range(10**5):
	m = (ok+bad)/2
	if is_ok(m):
		ok = m
	else:
		bad = m
print(ok)