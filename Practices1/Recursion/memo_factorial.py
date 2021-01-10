memo = dict()
def fact1(n):
    if n <= 1:
        return 1
    elif n in memo:
        # print('Found')
        return memo[n]
    else:
        cal = n * fact1(n-1)
        memo[n] = cal
        return cal

print(fact1(5))
print(fact1(20))
print(memo)