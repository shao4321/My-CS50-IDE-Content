class Numbers():

    MULTIPLIER = 1

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def add(self):
        return self.x + self.y

    @classmethod
    def multiply(cls, a):
        return a * cls.MULTIPLIER

    @staticmethod
    def substract(b, c):
        return b - c

    @property
    def values(self):
        print("Getting value...")
        return (self.x, self.y)

    @values.setter
    def values(self, xy_tup):
        print("Setting value...")
        if xy_tup[0] > 5:
            self.x = 10
            self.y = 20

    @values.deleter
    def values(self):
        print("Deleting value...")
        del self.x
        del self.y

num1 = Numbers(0, 0)
# print(num1.multiply(9))
print(Numbers.multiply(9))
# print(num1.substract(10, 7))
num2 = Numbers(5, 5)
num2.values = (6, 6)
# del(num2.values)
print(num2.values)
print(dir(num2))

test_num = Numbers(1, 1)
test_num.add().