from cs50 import get_float

mony = get_float("how much you want change :")
coin = 0

while mony <= 0:
    mony = get_float("how much you want change :")

cash = mony * 100

while cash >= 25:
    cash -= 25
    coin += 1

while cash >= 10:
    cash -= 10
    coin += 1

while cash >= 5:
    cash -= 5
    coin += 1

while cash >= 1:
    cash -= 1
    coin += 1

if cash == 0:
    print(coin)