def main():
    first()
    second()
    third()
    fourth()

def first():
    sum = 0
    for i in range(0, 100, 3):
        sum += i
    print(sum)

def second():
    sum = 0
    for i in range(0, 100):
        if i % 3 == 0:
            sum += i
    print(sum)

def third():
    sum = 0
    count = 0
    while count < 100:
        sum += count
        count += 3
    print(sum)

def fourth():
    sum = 0
    count = 0
    while count < 100:
        if count % 3 == 0:
            sum += count
        count += 1
    print(sum)

if __name__ == "__main__":
    main()
