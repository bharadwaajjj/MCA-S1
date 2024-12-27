a=input("Enter string : ").lower()
q=input("Enter the charecter : ").lower()
count=0
for i in a:
    if i==q:
        count+=1
print(f"The frequency of {q} in {a} is {count}")