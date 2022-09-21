from cs50 import get_float

while True:
    input = get_float("Changed owed: ") #ask for an input
    if input > 0:
        break
#print(input)

cents = round(input * 100)

#print(cents)

quarter = 25
dime = 10
nickel = 5
penny = 1


count = 0

while cents >= quarter: #check the cents whether are higher or equal to quarter
    count += 1 #count coins
    cents = cents - quarter  #remainder

#print(f"What is the number of coins after quarters: {count}")
#print(f"What is the remainder: {cents}")

while cents >= dime:
    count += 1
    cents = cents - dime

while cents >= nickel:
    count += 1
    cents = cents - nickel

while cents >= penny:
    count += 1
    cents = cents - penny

print(count)