#GCD of two numbers
a=int(input("Enter three numbers"))
b=int(input("Enter another number : "))
c=int(input("Enter another number : "))
for i in range(min(a,b,c),0,-1):
    if a%i==0 and b%i==0 and c%i==0:
        print("HCF is",i)
        break