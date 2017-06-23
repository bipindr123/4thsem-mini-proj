# -------------------------------------------------------------------------------
# Name:        Game novel
#
# Author:      alast/ Bipin
#
# Created:     20/06/2017
#
# Licence:     FREE TO DO ANYTHING WITH IT
# -------------------------------------------------------------------------------
import time
import random
import sys

yes = ['y', 'Y', 'Yes', 'YES', 'yes']
no = ['n', 'N', 'No', 'NO', 'no']
right = ['r', 'R', 'Right', 'RIGHT', 'right']
left = ['l', 'L', 'Left', 'LEFT', 'left']

battleover = 0
gundoor = 0
survival = 0
takem = 0
gun = 0
stick = 0


def creature():
    global battleover, gundoor, survival, takem, gun, stick
    print("As you proceed futher, you begin to make out two green, glowing, menacing eyes!")
    time.sleep(1)
    print("The eyes belong to an oversized creature resembling a gaint creature!")
    ch3 = str(input("It starts to creep towards you. Do you try to fight it? [Y/N]"))
    # WITH GUN
    if ch3 in yes:
        if ch1 in yes:
            print("You only have two bullets in the firearm to fight with!")
            print("You quickly shoot the creature in it's eye and weaken it")
            time.sleep(2)
        else:
            print("You quickly kick the creature in it's face, stunning it and gaining an advnatage over it.")
        print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
        print("                               Fighting...                   ")
        print("                      THE CREATURE BEGINS TO ATTACK")
        print(
            "YOU MUST HIT A SHOT ABOVE THE LEVEL OF THE CREATURE'S ATTACK TO KILL THE CREATURE WITH YOUR FINAL BULLET")
        print("             IF THE CREATURE HITS HIGHER THAN YOU, YOU WILL DIE")
        print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
        time.sleep(2)
        player = int(random.randint(3, 10))
        ai = int(random.randint(1, 5))
        print("You hit a shot of level", player)
        print("the creature hits you with attack level of", ai)
        time.sleep(2)

        if ai > player and ch3 in yes:
            print("The creature has dealt more damage than you!")
            battleover = 1
            survival = 0
            takem = 0

        elif ai == player and ch3 in yes:
            print(
                "You didn't do enough damage to kill the creature, but you manage to escape and run futher down the path.")
            battleover = 1
            survival = 1
            takem = 0

        elif player > ai and ch3 in yes:
            print("You killed the creature!")
            battleover = 1
            survival = 1
            takem = 0
    else:
        print("The creature crawls past you and you walk futher down the path.")
        survival = 1


print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
print("Welcome to the space text advanture game! VERSION 2.0")
print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
time.sleep(3)
print(
    "You wake up in a dark space station. It is pitch black and you can't remember anything. There is a small fiream on the gorund beside you.")
ch1 = str(input("Do you take it? [y/n]: "))

# GUN TAKEN
if ch1 in yes:
    print("You have taken the weapon!")
    time.sleep(2)
    gun = 1

# GUN NOT TAKEN
else:
    print("You did not take the weapon.")
    stick = 1

print(
    "As you proceed further into the space station, you reach an intersection between two paths. The path leading left is in complete darkness, the path leading right is also in complete darkness apart from the occasional flicker of some overhead lights.")
ch2 = str(input("Do you go left or right? [l/r]"))

# APPROACH CREATURE
if ch2 in right:
    door = 0
    creature()

if ch2 in left:
    door = 1
    print("You walk onwards and reach a locked door.")
    if ch1 in yes:
        door = 1
        gundoor = str(input("Do you shoot the lock with your gun? [y/n]"))
        if gundoor in yes:
            gundoor = 1
            print(
                "The door opens once you shoot the lock and you enter a small storeroom. Inside there is a large machine gun.")
            takem = str(input("Do you take the machine gun? [Y/N]"))
            if takem in yes:
                print("You have taken the machine gun!")
                takem = 1

            print("As this is a storeroom you must turn around are take another route. This is a dead end.")
            print("As you proceed futher, you begin to make out two green, glowing, menacing eyes!")
            print("The eyes belong to an oversized creature resembling a giant spider!")
            ch3 = str(input("It starts to creep towards you. Do you try to fight it? [Y/N]"))
            # machine gun and creature fight
            if takem == 1:
                print("You shoot your machine gun and the creature instantly dies.")
                survival = 1
            else:
                creature()
        else:
            takem = 0
            print(
                "It is impossible for you to enter through the door if you do not shoot the lock. You turn around and take the other route.")
            creature()

if survival == 0:
    print("GAME OVER YOU DIED")
    sys.exit()
else:
    print("You survive and walk on futher.")

if takem == 0:
    print(
        "5 more similar creatures creep up to you. With no ammunition left in your gun to defind yourself, you get overwhelmed and the creatures kill you.")
    print("GAME OVER YOU DIED")
    sys.exit()
else:
    print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
    print("                               Fighting...                   ")
    print(
        "5 more similar creatures creep up to you and start to attack. You must pick a number between 1 and 10 (including 1 and 10).")
    print(
        "There are 7 correct numbers. If you pick a number which is the same as of one of those 7 numbers you will survive.")
    print("If you pick a wrong number you will die.")
    number = int(input("What number do you choose?"))
    if number in [10, 9, 8, 7, 6]:
        print("That is the correct number! You manage to kill all the creatures and survive!")
    else:
        print("That is the incorrect number. The creatures kill you.")
        print("GAME OVER YOU DIED")
        sys.exit()

print(
    "You walk on until you reach an open door. You walk through the open door and reach the control room of the space station. The computer systems infrom you that the ship's thrusters are damaged.")
print("It states the chances of the ship landing safely to Earth is 70%. There is a 30% chance of death.")
print(
    "You could wait for rescue, however the chances of the space station bursting into flames within the next 7 days is 30% also. This would kill you.")
print("Also it is not known whether you will be rescued regardless of if the ship bursts into flames.")
getoffship = int(input("Enter 1 to attempt to land the ship on Earth. Or enter 2 to wait to be rescued."))

if getoffship == 1:
    chance1 = random.randint(1, 100)
    if chance1 <= 70:
        print("Congratulations! You have successfully landed the ship to Earth and completed the game.")
    else:
        print("The ship burst into flames whilst travelling to Earth")
        print("GAME OVER YOU DIED")
        sys.exit()

if getoffship == 2:
    chance2 = random.randint(1, 100)
    if chance2 <= 70:
        print("Congratulations! You have been successfully rescued and have completed the game.")
    else:
        print("The ship burst into flames whilst you were waiting to be rescued.")
        print("GAME OVER YOU DIED")
        sys.exit()
