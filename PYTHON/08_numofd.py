# count digits of a number

n = int(input("Enter a number : "))
count = 0
for _ in str(n):
    count += 1
print(count)