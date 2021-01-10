from sys import argv, exit
from cs50 import SQL

if len(argv) != 2:
    exit('Usage: python roster.py house_name')

db = SQL("sqlite:///students.db")

students_data = db.execute("SELECT first, middle, last, birth FROM students WHERE house= ? ORDER BY last ASC", argv[1])

for rows in students_data:
    if rows['middle'] == None:
        print("{} {}, born {}".format(rows['first'], rows['last'], rows['birth']))
    else:
        print("{} {} {}, born {}".format(rows['first'], rows['middle'], rows['last'], rows['birth']))