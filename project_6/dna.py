from sys import argv
import csv
import string

# 3 crucial aspects
# 1. def max_count_str -> counting number of STR in txt file -> choose the highest number
# 2. data structure (str_list) for pairing highest number of each STR with their name
# 3. def print_match -> checking the aspect 2 (pairing highest number of each STR with their name) + csv file -> match or not match


def max_count_str(content, str):  # 1. ASPECT

    count = [0] * len(content)  # creating array for text file
    # just illustration! [010010020003] for one STR, e. g. AGATC

    for i in range(len(content) - len(str), -1, -1):  # loop starting from the len of str (e. g. AGATC) and ending with len of the whole content (e. g. 1.txt)
# for i in range(len(str), len(content), 1):
        if content[i: i + len(str)] == str:  # str from content = str-> match
            if i + len(str) > len(content) - 1:  # if found match goes beyond content
                # moving index - depending on the i
                count[i] = 1  # count just 1
            else:
                count[i] = 1 + count[i + len(str)]  # sequence of STRs
        else:
            count[i] = 0  # no match -> index 0

    return max(count)  # max count for one STR, e. g. AGATC in the text file (e. g. 1.txt)


def match(csv_reader, str_pairing_list):  # find match str_list with provided csv_reader 3. ASPECT
    for row in csv_reader:
        name = row[0]
        values = [int(j) for j in row[1:]]# count_string has to be converted into int
        if values == str_pairing_list:
            print(name)
            return 0
        # else:
            # return 0
    print("No match")


def main():

    if len(argv) != 3:
        print("Write name of a CSV file and text file containing the DNA")
    else:
        with open(argv[1]) as csv_file:  # open CSV file
            csv_reader = csv.reader(csv_file)

            sequences_of_str = next(csv_reader)[1:]
            # first row without name -> AGATC, AATG, TAGC

            txtfile = open(argv[2], "r")  # open DNA sequence
            content = txtfile.read()
            #print(content, end="")

    # txtfile = open(argv[2], "r") open DNA sequence
    # content = txtfile.read()
    # print(content, end="")

            str_pairing_list = [max_count_str(content, str) for str in sequences_of_str]  # data structure - 2. ASPECT
        # initialize max_times_of_str(conent, str)
        # how many times of STRs is repeated in content -> return max(count)
        # e. g. AGATC is repeated 2x in content -> I get only 2
        # e. g. AATG is repeated 8x in content -> I get only 8
        # e. g. TATC is repeated 3x in content -> I get only 3

        # sequence for all sequences depending on the csv file
        # sequence represents the STR -1.sequence AGATC, 2. sequence AATG
        # 3. sequence TATC...in terms of small csv file

        # we get all the sequences (AGATC, AATG, TATC) from csv_reader
        # but only numbers and not the titles such as AGATC, AATG, TATC
        # 2 = AGATC
        # 8 = AATG
        # 3 = TATC

            match(csv_reader, str_pairing_list)

if __name__ == "__main__":
    main()