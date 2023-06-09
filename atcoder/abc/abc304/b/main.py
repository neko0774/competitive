N = int(input())
import math
k = max(0, len(str(N))-3)
ans = (N//(10**k))*10**k
print(ans)