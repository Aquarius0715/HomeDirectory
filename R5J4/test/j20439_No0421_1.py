n = int(input("Input: "))
for i in range(1, n+1):
    if i % 3 == 0:
        print("%d いまでしょ！" %(i))
        continue
    if '3' in str(i):
        print("%d いまでしょ！" %(i))
        continue
    print("%d いつやるか？" %(i))
