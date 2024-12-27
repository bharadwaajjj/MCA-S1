a=int(input("Enter the limit : "))
x=0
y=1
for i in range(a):
    s=x+y
    print(s,end=",")
    x=y
    y=s