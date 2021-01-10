# Inheritance, isinstance, issubclass

class Person:

    def __init__(self, name, age, country):
        self.__name = name #__double underscore does not permit access and editing outside of the class
        self.__age = age
        self._country = country #_single underscore tells us that we should access the attributes/methods within the scope of the class
                                #we can still access and edit outside of the class.

class Student(Person):

    def __init__(self, name, age, country, sch):
        super().__ninit__(name, age, country)
        self.sch = sch


p1 = Student('Jane', 23, 'Singapore', 'NUS')

print(p1.__dict__)

print(isinstance(p1, Student))
print(issubclass(Student, Person))