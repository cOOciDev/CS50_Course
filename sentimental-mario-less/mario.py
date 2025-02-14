from cs50 import get_int

height = get_int("Height :")

while height < 1 or height > 8:
    print("chouse between 1 and 8.")
    height = get_int("Height :")

if height > 0 or height < 9:
    space = height
    for line in range(height):

        for i in range(space - 1):
            print(" ", end="")

        for j in range(line + 1):
            print("#", end="")

        space -= 1
        print("")