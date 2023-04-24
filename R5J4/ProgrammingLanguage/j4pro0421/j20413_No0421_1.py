def main():
    while True:
        n = int(input("Type number(range 2-100000): "))
        if n >= 2 and n <= 100000:
            break
    for i in range(1, n+1):
        if i % 3 == 0 or '3' in str(i):
            print(str(i) + ": いまでしょ！")
        else:
            print(str(i) + ": いつやるか？")

if __name__ == "__main__":
    main()
