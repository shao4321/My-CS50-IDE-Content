# print(~12)
# print(12 & 13)
# print(12 | 13)
# print(12 ^ 13)
# print(12 << 3)
# print(12 >> 2)

def binary_to_decimal(binaryNum):
    binaryNum = str(binaryNum)
    res = 0
    mult = 1
    for n in range(len(binaryNum)-1, -1, -1):
        if binaryNum[n] == '1':
            res += mult
        mult *= 2
    return res

def decimal_to_binary(decNum):
    return "{0:b}".format(decNum)

binary_to_decimal(100110)
print(decimal_to_binary(117))