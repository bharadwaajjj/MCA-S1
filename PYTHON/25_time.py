class Time: 
    def __init__(self,hour,minute,second):
        self.__hour = hour
        self.__minute = minute
        self.__second = second

    def __add__(self, other):
        hour = self.__hour + other.__hour
        minute = self.__minute + other.__minute
        second = self.__second + other.__second
        if second >= 60:
            minute += second // 60
            second = second % 60
        if minute >= 60:
            hour += minute // 60
            minute = minute % 60
        if hour >= 24:
            hour = hour % 24
        return f"{hour:02}:{minute:02}:{second:02}"
    
time1=Time(12,50,00)

time2=Time(12,50,00)

print(time1+time2)