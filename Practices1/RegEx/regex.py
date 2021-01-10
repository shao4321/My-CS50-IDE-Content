import re
text = "aabb"

s = "a*b*"

pattern = re.compile(s)
equal = pattern.fullmatch(text)

print(equal)