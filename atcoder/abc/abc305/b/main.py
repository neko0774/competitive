p, q = input().split()
dist = [3, 1, 4, 1, 5, 9]
P = sum(dist[:ord(p)-ord("A")])
Q = sum(dist[:ord(q)-ord("A")])
print(abs(P-Q))