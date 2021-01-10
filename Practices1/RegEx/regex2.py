import re

pattern1 = re.compile(r'(?<=\n)')
pattern2 = re.compile(r'B(?=e)', re.I)

s = "bad cookie, good cookie, bad cookie, good cookie, good cookie"
pattern3 = r'(?<!c)ad'

txt = 'abed aBi'

# m = re.findall(pattern1, txt)
# print(m)
# print(len(m))

m2 = re.findall(pattern3, s)

print(m2)
print(len(m2))