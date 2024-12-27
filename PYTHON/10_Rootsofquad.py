# Find roots of a quadratic equation

import math
def findRoots(a,b,c):
    discriminant = b**2 - 4*a*c
    if discriminant > 0:
        root1= ((-b + math.sqrt(discriminant)) / (2*a))
        root2= ((-b - math.sqrt(discriminant)) / (2*a))
        print(f"The roots are real and distinct : {root1}, {root2}")
    elif discriminant == 0:
        root1 = -b/(2*a)
        print(f"The root are real and equal : {root1}")
    else:
        print("No real root")
        
a = int(input("Enter the Coefficient of x² : "))
b = int(input("Enter the Coefficient of x : "))
c = int(input("Enter the constant c : "))
findRoots(a,b,c)