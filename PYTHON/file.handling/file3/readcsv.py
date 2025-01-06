import csv
file = open("readcsv.csv","r")
reader = csv.reader(file)
list=[]
for row in reader:
    list.append(row)
print(list)