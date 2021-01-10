class Person:

    TITLES = ('Dr', 'Mr', 'Mrs', 'Ms')

    def __init__(self, title, name, age, country):
        if title not in self.TITLES:
            raise ValueError(f'{title} is not a valid title.')
        self.__title = title
        self.__name = name
        self.__age = age
        self._country = country
    def growUp(self, newAge):
        self.__age += newAge

obj1 = Person('Mrs', 'Jane', 23, 'Singapore')
print(obj1._Person__title)