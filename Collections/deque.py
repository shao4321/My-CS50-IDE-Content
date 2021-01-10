import collections
from collections import deque

d = deque('hello')
d.append('i')
d.appendleft(5)

d.popleft()
d.pop()

d.extend('123')
d.extendleft('456')
# d.clear()

print(d)
d.rotate(1)
print(d)

d.rotate(-2)
print(d)

# char from the front will get pop out if maxlen has exceeded
d2 = deque('hello', maxlen=5)
print(d2)
d2.append('a')
print(d2)

d2.reverse()
print(d2)

# maxlen can only be read and not overwrite
print(d2.maxlen)