#Sort Dictionary ascendiing and descendiing.
dict1={2:"hjdgwej",4:"huhwdu",1:"guyg",3:"hucgsf"}
mylist=list(dict1.keys())
print(mylist)
mylist.sort()
print(mylist)
print("{",end="")
for i in mylist:
    print(i," : ",dict1[i]," , ",end="")
print("}",end="")
print("{",end="")
for i in mylist[::-1]:
    print(i," : ",dict1[i]," , ",end="")