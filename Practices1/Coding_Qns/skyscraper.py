'''Edabit Qn
Create a function that takes a skyline (2-D list of 0's and 1's) and returns the height of the tallest skyscraper.'''

buildings_dict = dict()
def tallest_skyscraper(lst):
	for buildings in lst:
		i = 0
		for building in range(len(buildings)-1, -1, -1):
			if buildings[building]:
				if i in buildings_dict:
					buildings_dict[i] += 1
				else:
					buildings_dict[i] = 1
			i += 1
	buildings_height = []
	for height in buildings_dict.values():
		buildings_height.append(height)
	# print(buildings_dict)
	# print(buildings_height)
	return max(buildings_height)

test = [
	[0, 1, 0, 0, 0, 0],
	[0, 1, 0, 0, 0, 0],
	[0, 1, 0, 0, 0, 0],
	[1, 1, 1, 1, 0, 0],
	[1, 1, 1, 1, 1, 1]
]
print(tallest_skyscraper(test))