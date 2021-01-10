# Use of hasattr, getattr, setattr

class Person:

    def __init__(self, name, age, country):
        self.__name = name #__double underscore does not permit access and editing outside of the class
        self.__age = age
        self._country = country #_single underscore tells us that we should access the attributes/methods within the scope of the class
                                #we can still access and edit outside of the class.

obj1 = Person('Jane', 23, 'Singapore')

print(hasattr(obj1, '_Person__name'))
setattr(obj1, '_country', 'Malaysia')

print(getattr(obj1, '_Person__age')) # same as obj1._Person__age