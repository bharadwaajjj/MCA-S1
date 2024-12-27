#Merge two dictionares
n=input("Enter Keys for Dict1 : ").split()
dict1={}
for i in n:
    value=input(f"Enter Values for {i} : ")
    dict1[i]=value
#dictionary 2
m=input("Enter Keys for Dict1 : ")
dict2={}
for i in m:
    value=input(f"Enter Values for {i} : ")
    dict2[i]=value
#merging
dict3=dict1
dict3.update(dict2)
print(dict3)
