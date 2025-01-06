myFile = open("C:/Users/cacet/Desktop/sandra/labcycle2/new.txt")
i=0
destfile = open("C:/Users/cacet/Desktop/sandra/labcycle2/destfile.txt","r+")
for lines in myFile:
    i+=1
    if(i%2==1):
        destfile.write(lines)
    else:
        continue
myList =[]
for lines in destfile:
    myList.append(lines)

print(myList)

