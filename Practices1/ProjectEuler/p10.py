# Project Euler Problem Set 10

def isPrime(num):
    if num > 1:
        for n in range(2, num):
            if num % n == 0:
                return False
        else:
            return True
    else:
        return False

if __name__=="__main__":
    total = 0
    for i in range(2_000_000):
        if isPrime(i):
            total += i
    print(total)