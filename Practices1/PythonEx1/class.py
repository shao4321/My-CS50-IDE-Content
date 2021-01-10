class Person:
    def __init__(self, name):
        self.name = name
    def talk(self):
        print(f'Hi, I am {self.name}')


p1 = Person("Shao")

print(p1.name)
p1.talk()

p2 = Person("Bob")

print(p2.name)