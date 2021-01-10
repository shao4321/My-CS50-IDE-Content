def mergeSort(lst):
    if len(lst) > 1:
        # Finding the middle
        mid = len(lst)//2

        # Copy data into 2 temp lists
        lowHalf = lst[:mid]
        highHalf = lst[mid:]

        # Recursive call for subproblem
        mergeSort(lowHalf)
        mergeSort(highHalf)

        # Initial index of first & second subarray
        lowHalf_index = highHalf_index = merged_index = 0

        # Compare and place the smaller value of the 2 list into the merged list
        while lowHalf_index < len(lowHalf) and highHalf_index < len(highHalf):
            if lowHalf[lowHalf_index] < highHalf[highHalf_index]:
                lst[merged_index] = lowHalf[lowHalf_index]
                lowHalf_index += 1
            else:
                lst[merged_index] = highHalf[highHalf_index]
                highHalf_index += 1
            merged_index += 1

        # Copy the remaining data of lowHalf list if any
        while lowHalf_index < len(lowHalf):
            lst[merged_index] = lowHalf[lowHalf_index]
            lowHalf_index += 1
            merged_index += 1

        # Copy the remaining data of highHalf list if any
        while highHalf_index < len(highHalf):
            lst[merged_index] = highHalf[highHalf_index]
            highHalf_index += 1
            merged_index += 1


if __name__== "__main__":

    a = [3, 5, 1, 7, 2, 0, 12, 4]
    print(f"Given list is: {a}")
    mergeSort(a)
    print(f"Sorted list is: {a}")