# First n multiples of a number

n = int(input("Enter  a number : "))
limit = int(input("Enter a limit : "))
for i in range(1, limit+1):
    print(f"{n}X{i}={n*i}")