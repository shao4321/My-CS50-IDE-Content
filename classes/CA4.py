# Using @classmethods and @staticmethods

class Person:

    def __init__(self, name, age, pay):
        self._name = name
        self._age = age
        self._pay = int(pay)

    @classmethod
    def from_string(cls, ppl):
        name, age, pay = ppl.split()
        return cls(name, age, pay)

    @staticmethod
    def is_workday(day):
        return day.weekday() >= 0 and day.weekday() < 5
        
    def above_avg_pay(self):
        if self._pay > 3000:
            print(f"{self._name} pay is above average.")
        else:
            print(f"{self._name} pay is below average.")
        

p1 = 'ShaoWee 24 2500'

new_p1 = Person.from_string(p1)

new_p1.above_avg_pay()
# print(new_p1._pay)

# from datetime import datetime
# today = datetime.now()
# print(today.weekday())
# print(Person.is_workday(today))