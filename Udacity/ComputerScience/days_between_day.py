def IsLeapyear(year):
    if year % 4 == 0 and year % 100 != 0:
        return True
    if year % 400 == 0 and year % 100 != 0:
        return True
    if year % 100 == 0:
        return False
    else:
        return False


def DayOfMonth(year, month):
    if month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12:
        return 31
    if month == 2:
        if IsLeapyear(year):
            return 29
        else:
            return 28
    else:
        return 30


def nextDay(year, month, day):
    """Simple version: assume every month has 30 days"""
    if day < DayOfMonth(year, month):
        return year, month, day + 1
    else:
        if month == 12:
            return year + 1, 1, 1
        else:
            return year, month + 1, 1


def dateIsBefore(year1, month1, day1, year2, month2, day2):
    if year1 < year2:
        return True
    if year1 == year2:
        if month1 < month2:
            return True
        if month1 == month2:
            return day1 < day2
    return False

def daysBetweenDates(year1, month1, day1, year2, month2, day2):
    assert not dateIsBefore(year2, month2, day2, year1, month1, day1)
    days = 0
    while dateIsBefore(year1, month1, day1, year2, month2, day2):
        year1, month1, day1 = nextDay(year1, month1, day1)
        days += 1
    return days