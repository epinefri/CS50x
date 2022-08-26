# prints a half-pyramid of a specified height

while True:
    try:
        height = int(input("Height: "))
        if height > 0 and height < 9:
            break
    except:
        continue

for i in range(height):
    print(" " * (height - i - 1), end="")
    print("#" * (i + 1))