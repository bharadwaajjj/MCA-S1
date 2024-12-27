n=int(input("Enter limit for Factorial : "))
def fact(b):
    if b:
        f=b*fact(b-1)
        return f
    else:
        return 1
print("The factorial is : ",fact(n))
