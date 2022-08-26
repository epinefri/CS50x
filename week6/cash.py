# calculate the minimum number of coins required to give a user change

while True:
    try:
        dollars = float(input("Change owed: "))
        if (dollars >= 0):
            break
    except:
        continue


cents = dollars * 100

quarters = int(cents / 25)
cents = cents - quarters * 25

dimes = int(cents / 10)
cents = cents - dimes * 10

nickels = int(cents / 5)
cents = cents - nickels * 5

pennies = int(cents / 1)
cents = cents - pennies * 1

print(quarters + dimes + nickels + pennies)