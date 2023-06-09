def main():
    S = input()
    def check(x):
        return "A"<=x<="Z"
    if len(S)==8 and check(S[0]) and check(S[-1]) and S[1:-1].isdigit() and 100000<=int(S[1:-1])<=999999:
        print("Yes")
    else:
        print("No")



main()