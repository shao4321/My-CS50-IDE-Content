# Special Dunder Methods

class Person:

    def __init__(self, name, age, country):
        self._name = name #__double underscore does not permit access and editing outside of the class
        self.__age = age
        self._country = country #_single underscore tells us that we should access the attributes/methods within the scope of the class
                                #we can still access and edit outside of the class.

class Student(Person):

    def __init__(self, name, age, country, sch):
        super().__init__(name, age, country)
        self.sch = sch

    def __str__(self):
        return f"My name is {self._name}"

    def __repr__(self):
        return f"Your name is {self._name}"

    def __add__(self, other):
        return self._Person__age + other._Person__age

    def __len__(self):
        return len(self._name)

p1 = Student('Jane', 23, 'Singapore', 'NUS')
p2 = Student('Kim', 24, 'Korean', 'NUS')

print(p1 + p2)
print(p1)

print(len(p2))
del(p1)
print(p2._country)