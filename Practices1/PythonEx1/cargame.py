started = False

while True:
    command = input(">").lower()
    if command == "help":
        print("""
start - to start the car
stop - to stop the car
quit - to quit
""")
    elif command == "start":
        if started == False:
            print("Car started...Ready to go!")
            started = True
        else:
            print("Car has already started.")

    elif command == "stop":
        if not started == False:
            print("Car stopped.")
            started = False
        else:
            print("Car has already been stopped.")

    elif command == "quit":
        if started == True:
            print("Please stop the car before you quit")
        else:
            break
    else:
        print("I don't understand that...")

