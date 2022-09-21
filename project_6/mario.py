from cs50 import get_int

def main():
    h = get_positive_integer()

    for i in range(h):
        for j in range(i, h - 1):
            print(" ", end="")
        for k in range(i + 1):
            print("#", end="")
        print()

def get_positive_integer():
    while True:
        height = get_int("Height: ")
        if height <= 8 and height >=1:
            break
    return height

main()