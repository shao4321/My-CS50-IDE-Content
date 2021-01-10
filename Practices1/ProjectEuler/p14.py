def find_chain_length(n):
    cnt = 1
    while n != 1:
        if n % 2 == 0:
            n /= 2
        else:
            n = 3*n + 1
        cnt += 1
    return cnt

if __name__ == "__main__":
    maxlength = 0
    for i in range(2, 1_000_000):
        l = find_chain_length(i)
        if maxlength < l:
            maxlength = l
            maxL_num = i
    print(maxlength)
    print(maxL_num)