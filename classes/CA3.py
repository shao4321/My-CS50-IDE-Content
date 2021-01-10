class Person:

    def __init__(self, pets):
        self._pets = pets

    def addPet(self, petType):
        self._pets.append(petType)

    def delPet(self, petType):
        lowerCasePets = [p.lower() for p in self._pets]
        if petType.lower() not in lowerCasePets:
            raise ValueError("'%s' is not in your pet collection" %petType)
        index = lowerCasePets.index(petType.lower())
        self._pets.pop(index)

p1 = Person(['Dog', 'Cat'])
p1.addPet('Mouse')
print(p1._pets)
p1.delPet('doG')
print(p1._pets)