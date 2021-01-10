def create_square(length):
	if not length or length <= 0:
		return ''
	s = ''
	for i in range(length):
		if i == 0 or i == length - 1:
			for k in range(length):
				s += '#'
			s += '\n'
			continue
		s += '#'
		for k in range(length-2):
			s += ' '
		s += '#'
		s += '\n'
	s = s.strip('\n')
	return s

print(create_square(15))