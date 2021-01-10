import datetime

class Person:

    def __init__(self, name, surname, birthdate, address, telephone):
        self.name = name
        self.surname = surname
        self.birthdate = birthdate

        self.address = address
        self.telephone = telephone

    def __str__(self):
        return \
        """\tMy name is %s %s, my birthday falls on %s.
        Below is my address:
        %s
        You can contact me at %s or %s""" \
        %(self.surname, self.name, self.birthdate, self.address, self.telephone, self.email())

    def __eq__(self, other):
        return self.age() == other.age()

    def email(self):
        email = f"{self.name}.{self.surname}@example.com"
        return email

    def age(self):
        today = datetime.date.today()
        age = today.year - self.birthdate.year

        if today < datetime.date(today.year, self.birthdate.month, self.birthdate.day):
            age -= 1

        return age


person1 = Person(
    "Jane",
    "Doe",
    datetime.date(1992, 3, 12), # year, month, day
    "No. 12 Short Street, Greenville",
    "555 456 0987"
)

person2 = Person(
    "John",
    "Smith",
    datetime.date(1984, 5, 15), # year, month, day
    "No. 56 High Street, Greenwitch",
    "556 789 0127"
)
print(person1 == person2)
