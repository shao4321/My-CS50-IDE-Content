# Class methods - alternative constructor

class Date:
    def __init__(self, Year, Month, Day):
        self.year  = Year
        self.month = Month
        self.day   = Day

    def __str__(self):
        return 'Date({}, {}, {})'.format(self.year, self.month, self.day)

    def set_date(self, y, m, d):
        self.year = y
        self.month = m
        self.day = d

    @classmethod
    def from_str(cls, date_str):
        '''Call as
           d = Date.from_str('2013-12-30')
        '''
        print(cls)
        year, month, day = map(int, date_str.split('-'))
        return cls(year, month, day)


d = Date(2013, 11, 22)
print(d)

d.set_date(2014, 1, 27)
print(d)

print('')
dd = Date.from_str('2013-10-20')
print(dd)

print('')
z = d.from_str('2012-10-20')
print(d)
print(z)