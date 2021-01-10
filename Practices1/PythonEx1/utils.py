def find_max(numbers):
    Max = numbers[0]
    for number in numbers:
        if number > Max:
            Max = number
    return Max