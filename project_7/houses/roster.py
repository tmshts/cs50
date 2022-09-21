# TODO
from sys import argv, exit
from cs50 import SQL
import sqlite3

# Open the file for SQLite
db = SQL("sqlite:///students.db")

# Check the len of argv
if len(argv) != 2:
    print("Wrong command line argument")
    exit(1)
else:
    house_ar = argv[1]

# print(house_ar)
# print()

    for row in db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", house_ar):
        # print(row)
        first = row["first"]
        middle = row["middle"]
        last = row["last"]
        house = row["house"]
        birth = row["birth"]

        if middle == None:
            print(f"{first} {last}, born {birth}")
        else:
            print(f"{first} {middle} {last}, born {birth}")