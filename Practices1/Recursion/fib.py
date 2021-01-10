# Using Memoization to improve time efficiency
memo = dict()
def fib(n):
    if n <= 2:
        return 1
    elif n in memo:
        return memo[n]
    else:
        result = fib(n-1) + fib(n-2)
        memo[n] = result
        return result

if __name__=="__main__":
    cnt = 0
    while True:
        fib_num = fib(cnt)
        if len(str(fib_num)) == 1000:
            break
        cnt += 1
    print(cnt)