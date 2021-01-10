def is_TGL_num(num):
    total = 0
    i = 1
    while total < num:
        total += i
        if num == total:
            return True
        i += 1
    return False

def check_no_of_div(num):
    lst = []
    for n in range(1, num + 1):
        if num % n == 0:
            lst.append(n)
    return lst

if __name__=="__main__":
    counter = 1
    while True:
        if is_TGL_num(counter):
            numDiv_lst = check_no_of_div(counter)
        if len(numDiv_lst) > 500:
            break
        counter+=1
    print(counter)