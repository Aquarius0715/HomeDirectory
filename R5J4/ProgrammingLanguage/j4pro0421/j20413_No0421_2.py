import sys

string = "1, 45"
sum = 0

for i in string.split(","):
    try:
        sum += int(i)
    except ValueError:
        print("Input Error")
        sys.exit()

print("sum=" + str(sum))
