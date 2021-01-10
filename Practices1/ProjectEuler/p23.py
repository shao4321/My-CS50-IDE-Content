def is_abundant_num(n):
    total = 0
    for i in range(1, n):
        if n % i == 0:
            total += i
        if total > n:
            return True
    else:
        return False

if __name__== "__main__":

    abundant_nums = []
    for i in range(0, 28124):
        if is_abundant_num(i):
            abundant_nums.append(i)

    sum_abundant_nums = set()
    for num1 in range(0, len(abundant_nums)-1):
        for num2 in range(num1+1, len(abundant_nums)):
            SUM = abundant_nums[num1] + abundant_nums[num2]
            if SUM > 28123:
                break
            else:
                sum_abundant_nums.add(SUM)

    res = 0
    for num in range(0, 28124):
        if num not in sum_abundant_nums:
            res += num

    print(sum_abundant_nums)
    print(res)