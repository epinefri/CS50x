# prints out a double half-pyramid of a specified height

while True:
    try:
        height = int(input("Height: "))
        if 0 < height < 9:
            break
    except:
        continue

for i in range(height):
    # print spaces
    print(" " * (height - i - 1), end="")

    # print left hashes
    print("#" * (i + 1), end="")

    # print middle spaces
    print("  ", end="")

    # print right hashes
    print("#" * (i + 1))