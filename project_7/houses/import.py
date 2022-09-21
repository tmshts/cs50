# TODO
from sys import argv, exit
import csv
from cs50 import SQL
import dis

# Open the file for SQLite
db = SQL("sqlite:///students.db")

# check with argv
if len(argv) != 2:
    print("Wrong command-line argument")
    exit(1)

# Read the CSV file
with open(argv[1], "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        mix = row["name"].split(" ")
        count = len(row["name"].split(" "))
        house = row["house"]
        birth = row["birth"]
        #print(house, end="|")
        #print(birth, end="|")

        if count == 3:
            first = mix[0]
            middle = mix[1]
            last = mix[2]

            #print(first, end="|")
            #print(middle, end="|")
            #print(last)
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first, middle, last, house, birth)
            #continue
        else:
            first = mix[0]
            middle = None
            last = mix[1]

            #print(first, end="|")
            #print(middle, end="|")
            #print(last)

            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first, middle, last, house, birth)