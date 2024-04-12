N = int(input())
print(*["o" if (i+1)%3!=0 else "x" for i in range(N)], sep='')