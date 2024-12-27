# factorial of a number

def fac(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n*fac(n-1)             # for eg: 5! will be   5 * fact(4) and the same happens with 4
n = int(input("Enter a Number : "))
print("Factorial of Number is" , fac(n))