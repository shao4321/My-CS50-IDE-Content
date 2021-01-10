def sum_of_divisor(n):
	total = 0
	for i in range(1, n):
		if n % i == 0:
			total += i
	return total

if __name__ == "__main__":
	test_set = 1000
	total = 0
	for nums in range(test_set):
		a = sum_of_divisor(nums)
		for i in range(test_set):
			b = sum_of_divisor(i)
			if a == b:
				total += a + b
	print(total)