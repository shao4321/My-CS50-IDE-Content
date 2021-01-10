import collections
from collections import namedtuple

Point = namedtuple('Point', 'x y z')

newP = Point(3, 4, 5)
print(newP)
print(newP.x, newP.y, newP.z)
print(newP._asdict())
print(newP._fields)

newP = newP._replace(x=1)
print(newP)