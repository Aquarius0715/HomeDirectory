import random
f = open('words.dat','r')
data = []
for line in f:
    data.append(line.rstrip("\n"))
f.close()
print(random.choice(data))
