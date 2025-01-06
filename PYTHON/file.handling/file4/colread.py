import csv
with open("readcsv.csv","r") as csvfile:
    reader = csv.reader(csvfile)
    n = int(input("Enter the specific columns of your choice: "))
    col = []
    for row in reader:
        col.append(row[n])
    print(col)