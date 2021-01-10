class Generic():

    def __init__(self, *args):
        self.first_name = args[0]
        self.last_name = args[1]

    def __str__(self):
        return self.first_name + ' ' + self.last_name + ' Belonging to Class: ' + str(type(self).__name__)

p1 = Generic('Shao Wee', 'Lee')
print(p1)