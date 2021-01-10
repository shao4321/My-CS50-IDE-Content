import random


class Dice:
    def roll(self):
        first_num = random.randint(1, 6)
        second_num = random.randint(1, 6)
        return first_num, second_num


d1 = Dice()
print(d1.roll())
