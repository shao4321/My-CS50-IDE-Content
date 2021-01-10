while True:
    changeOwed = float(input("Change owed: "))
    if changeOwed > 0:
        break

coins = [0,0,0,0]
y, x, m, n = coins

#y is the number of 0.25cents coins
#x is the number of 0.10cents coins
#m is the number of 0.05cents coins
#n is the number of 0.01cents coins

changeAmtFormatted = changeOwed * 100

while changeAmtFormatted >= 25:
    changeAmtFormatted -= 25
    y+=1
while changeAmtFormatted >= 10:
    changeAmtFormatted -= 10
    x+=1
while changeAmtFormatted >= 5:
    changeAmtFormatted -= 5
    m+=1
while changeAmtFormatted >= 1:
    changeAmtFormatted -= 1
    n+=1

coins = y, x, m, n
total_coins = sum(coins)
print(total_coins)