import sys
import csv
from cs50 import SQL


if len(sys.argv) != 2:
    sys.exit('Usage: python import.py file.csv')

#Opening and reading the CSV file
with open(sys.argv[1], "r") as csv_file:
    if csv_file.readable() == False:
        sys.exit('Error reading CSV file')
    reader = csv.reader(csv_file)

#Creating a table to store the information in csv file
    tables = []
    for row in reader:
        tables.append(row)

#Splitting the names to first, middle and last
name_list = []
j = 1
for i in range(len(tables) - 1):
    name_list.append(tables[j][0].split(' '))
    j += 1

#Assigning NULL for NA middle_name & Concatenate the names with the other informations
k = 1
for i in range(len(name_list)):
    if(len(name_list[i]) != 3):
        name_list[i].insert(1, None)
    name_list[i].append(tables[k][1])
    name_list[i].append(int(tables[k][2]))
    k += 1

#Delete unnecessary table
tables.clear()

#Storing informations in database
db = SQL("sqlite:///students.db")

ID = 0
for rows in name_list:
    first_name = rows[0]
    middle_name = rows[1]
    last_name = rows[2]
    house = rows[3]
    birth = rows[4]
    db.execute("INSERT INTO students VALUES(?, ?, ?, ?, ?, ?)", ID, first_name, middle_name, last_name, house, birth)
    ID += 1