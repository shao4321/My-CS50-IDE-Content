# Project Euler Problem Set 5

def divisible(num, count):
    return num % count == 0

if __name__ == "__main__":
    start = 20
    count = 1
    while start < 999_999:
        if divisible(start, count):
            count += 1
        else:
            start += 1
            count = 1
        if count == 18:
            break
    print(start)