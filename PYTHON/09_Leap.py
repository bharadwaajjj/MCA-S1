# Check Leap Year

def isLeapYear(year):
    if year%100==0:
        if year%400==0:
            return True
        else:
            return False
    if year%4==0:
        return True
    else:
        return False

year = int(input("Enter a Year : "))
if(isLeapYear(year)):
    print(f"{year} is a leap year")
else:
    print(f"{year} is not a leap year")