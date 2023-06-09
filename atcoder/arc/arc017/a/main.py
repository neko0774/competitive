N = int(input())

def is_prime(number) -> int:
    if number < 2: return 0
    if number==2: return 1
    if number%2==0: return 0
    i = 3
    while i*i <= number:
        if number%i==0:
            return 0
        i+=2
    return 1

print("YES" if is_prime(N) else "NO")