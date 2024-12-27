#Display first and last color from a comma seperated list of colors
lis=list(input("Enter your colors : ").split(","))
print(f"First and last color of {lis} is \nFirst : {lis[0]} \nLast : {lis[-1]}")