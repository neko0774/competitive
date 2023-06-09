X, Y = map(int, input().split())
def score(x):
    return max(0, 400000-100000*x)
print(score(X)+score(Y)+ (400000 if X==Y==1 else 0) )