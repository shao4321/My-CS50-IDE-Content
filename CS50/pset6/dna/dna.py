import sys
import csv
import re

#Exit when arguments given is not correct
if len(sys.argv) != 3:
    sys.exit('Usage: python dna.py data.csv sequence.txt')

#Open and read CSV file
with open(sys.argv[1], "r") as csv_file:
    if csv_file.readable() == False:
        sys.exit('Error reading CSV file')
    read_csv = csv_file.readline()
    headers = list(read_csv.split(','))
    headers.remove('name')
    headers[len(headers) - 1] = headers[len(headers) - 1].rstrip('\n')

#Open and read sequence file
with open(sys.argv[2], "r") as sequence_file:
    if sequence_file.readable() == False:
        sys.exit('Error reading sequence file')
    read_sequence = sequence_file.read()

#Storing the maximum STR counts for each different STR type in a list
maxSTRcount_list = []

#Making comparision on the STR(s) to the sequences

#Traversing through all the listed STR(s) in loaded database
for i in range(0, len(headers)):
    j = 0
    STRcount = 0
    maxSTRcount = 0
    
    #Looping through the sequence file to calculate matches
    while j < len(read_sequence):
        if re.match(headers[i], read_sequence[j:]):
            STRcount += 1
            j += len(headers[i])
        else:
            if STRcount > maxSTRcount:
                maxSTRcount = STRcount
            STRcount = 0
            j += 1
    maxSTRcount_list.append(maxSTRcount)

#Matching of the STR counts to the databases
with open(sys.argv[1], "r") as csv_file:
    if csv_file.readable() == False:
        sys.exit('Error reading CSV file')
    read_csv2 = csv.reader(csv_file)
    row = next(read_csv2)
    matched = False
    for row in read_csv2:
        name = row[0]
        del row[0]
        rowInt = list(map(int,row))
        if rowInt == maxSTRcount_list:
            print(name)
            matched = True
            break
    if matched == False:
            print("No match")


