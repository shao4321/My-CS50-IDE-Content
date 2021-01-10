def check_recurring(dec):
    p1 = 2
    cnt = 0
    similar = ""
    sim = ""
    string_dec = str(dec)
    for d in range(2, len(string_dec)):
        if d in sim:
            cnt += 1
        sim += string_dec[d]

        if string_dec[p1] == string_dec[d] and string_dec[p1] != similar:
            similar = string_dec[p1]
            cnt += 1
        p1 += 1
    return cnt

if __name__=="__main__":
    print(1/7)
    print(check_recurring(1/7))
    # longest_recur_len = 0
    # for i in range(2, 10):
    #     recur_len = check_recurring(1/i)
    #     if recur_len > longest_recur_len:
    #         longest_recur_len = recur_len
    # print(longest_recur_len)