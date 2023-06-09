def solve(x):
    ret = 0
    for i in range(int(x)+1):
        if i%13==5: ret += 1
    return ret

print(solve(999999))
