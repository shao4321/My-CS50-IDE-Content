correct_number = 9

guess_status = False
guess_limit = 3
guess_count = 0

while guess_count < guess_limit:
    guess = int(input(f"Guess {guess_count + 1}: "))
    guess_count += 1
    if guess == correct_number:
        guess_status = True
        break

if guess_status == True:
    print("Yon Won!")
    print(f"You guessed it in {guess_count} guess.")
else:
    print("You Lost.")