'''Edabit
"Sort by Frequency"
Create a function that takes a list of integers lst and sort the elements of the list by decreasing frequency of the elements.
If two elements have the same frequency, sort them by increasing value.'''

def sort_freq(lst):
	old_dict = dict()
	freq_list = []
	dup_list = []
	res_list = []
	for n in lst:
		if n in old_dict:
			old_dict[n] += 1
		else:
			old_dict[n] = 1
	for freq in old_dict.values():
		freq_list.append(freq)
	freq_list.sort()
	new_dict = {}
	for key, value in old_dict.items():
	   if value in new_dict:
	       new_dict[value].append(key)
	   else:
	       new_dict[value]=[key]
	new_dict_list = sorted(new_dict,reverse=True)
	for key in new_dict_list:
		new_dict[key].sort()
		for j in range(len(new_dict[key])):
			for i in range(key):
				res_list.append(new_dict[key][j])
	return res_list


test = [2, 3, 5, 3, 7, 9, 5, 3, 7]
test2 = [4, 4, 2, 5, 1, 1, 3, 3, 2, 8]
test3 = [1, 2, 3, 0, 5, 0, 1, 6, 8, 8, 6, 9, 1]
print(sort_freq(test3))