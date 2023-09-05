
while True:
    try:
        height = int(input("Height: "))
        if 0 < height <= 8:
            break
    except ValueError:
        continue


for i in range(height):
    print(" " * (height - (i + 1)), end="")
    print("#" * (i + 1))
