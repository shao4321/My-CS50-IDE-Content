memo = dict()
def fact(num):
    if num <= 1:
        return 1
    elif num in memo:
        return memo[num]
    else:
        memo[num] = num * fact(num-1)
        return memo[num]

def isCurious(n):
    n = str(n)
    total = 0
    for i in range(len(n)):
        total += fact(int(n[i]))
    return total == int(n)

if __name__=="__main__":
    res_lst = []
    for i in range(3, 1000000):
        if isCurious(i):
            res_lst.append(i)
    print(sum(res_lst))