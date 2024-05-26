import random
MIN = 50
MAX = 250
guess_number = 10
game = "y"
best_score = 10

while game == "y":
    random_num = random.randint(MIN, MAX+1)
    guess_list = []
    for i in range(1,guess_number+1):
        x = int(input(f"Enter a number between {MIN} and {MAX}: "))
        while x < MIN or x > MAX:
            print("Invalid")
            x = int(input(f"Please enter a number between {MIN} and {MAX}: "))
        guess_list.append(x)
        if x == random_num:
            print("You won.")
            break
        if x > random_num:
            print("Too high")
        else:
            print("Too low")
    if i < best_score:
        best_score = i
        print(f"Your new best score is {best_score}")
    else:
        print(f"Your best score is {best_score}")
    print(f"The number was {random_num}")
    print(f"Your guesses: {guess_list}")
    game = input("Would you like to play again ? (y/n): ")
print("Thanks for playing!")