height = int(input("Height: "))

while height < 1 or height > 8:
    print("Please enter a value between 1 to 8.")
    height = int(input("Height: "))
    
z = height

for i in range(0, height):
    for k in range(z - 1, 0, -1):
        print(" ", end="")
    print("#", end="")
    for y in range(i):
        print("#", end="")
    z-= 1
    print("  ",end="")
    for q in range(i + 1):
        print("#", end="")
    print()