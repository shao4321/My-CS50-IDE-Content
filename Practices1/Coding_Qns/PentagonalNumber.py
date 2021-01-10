inners = {}
lst = []

def pent(n):
    if n <= 0:
        inners[n] = 1
        lst.append(inners[n])
        return 1
    if n == 1:
        inners[n] = 1
        lst.append(inners[n])
        return 5 * n + inners[n]
    else:
        inners[n] = pent(n-1)
        lst.append(inners[n])
        return 5 * n + inners[n]

print(pent(8))
print(lst)
print(inners)