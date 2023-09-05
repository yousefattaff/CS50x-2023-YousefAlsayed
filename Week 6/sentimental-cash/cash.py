import cs50

while True:
    try:
        dollars = cs50.get_float("Change owed: ")
        if dollars >= 0:
            break
    except ValueError:
        continue
dollars = dollars * 100
quarters = dollars // 25
dollars = dollars - quarters * 25
dimes = dollars // 10
dollars = dollars - dimes * 10
nickles = dollars // 5
dollars = dollars - nickles * 5
pennies = dollars // 1
dollars = dollars - pennies * 1
coins = quarters + dimes + pennies + nickles
print(int(coins))
