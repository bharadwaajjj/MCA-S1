# Arithematic operations

choice = 0
while(choice != 5):
    choice = int(input("\n\n.....Choose an operation.....\n1.Addition\n2.Subtraction\n3.Division\n4.Multiplication\n5.Exit\nOption:"))
    if choice == 1:
        a=int(input("Enter the first number:"))
        b=int(input("Enter the second number:"))
        print(f"The sum is {a + b}")
    if choice == 2:
        a=int(input("Enter the first number:"))
        b=int(input("Enter the second number:"))
        print(f"The difference is {a - b}")
    if choice == 3:
        a=int(input("Enter the first number:"))
        b=int(input("Enter the second number:"))
        print(f"The quotient is {a / b}")
    if choice == 4:
        a=int(input("Enter the first number:"))
        b=int(input("Enter the second number:"))
        print(f"The product is {a * b}")
    if choice == 5:
        print("...Exiting...")
        break