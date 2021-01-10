# List must be sorted
# Time Complexity: base-2 logarithm of n where n is the number of items in array
def binary_search(num, lst):
    min_index = 0
    max_index = len(lst) - 1
    while True:
        if max_index < min_index:
            return f"{num} is not present in list"
        mid_index = round((min_index + max_index) / 2)
        if lst[mid_index] == num:
            return "Found"
        if num > lst[mid_index]:
            min_index = mid_index + 1
        else:
            max_index = mid_index - 1

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
print(binary_search(61, primes))