def SelectionSort(lst):
    for i in range(len(lst) - 1):
        for j in range(i + 1, len(lst)):
            if lst[i] > lst[j]:
                lst[i], lst[j] = lst[j], lst[i]
    return lst


def InsertionSort(lst):
    for i in range(1, len(lst)):
        temp = lst[i]
        hole = i
        while temp < lst[hole - 1] and hole > 0:
            lst[hole] = lst[hole - 1]
            hole -= 1
        lst[hole] = temp
    return lst


a = [5, 6, 2, 1, 8]
print(SelectionSort(a))
print(InsertionSort(a))