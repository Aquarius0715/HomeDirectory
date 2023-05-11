import random

class Dictionary:
    def __init__(self, id, word, means):
        self.id = id
        self.word = word
        self.means = means;

def main():
    data = loadDictionary();
    rand = random.choice(data)
    print(rand.word)

def loadDictionary():
    data: [Dictionary] = []
    file = open('words.dat', 'r')
    for rows in file:
        row = rows.rstrip("\n").split(' ')
        data.append(Dictionary(row[0], row[1], row[2]))
    file.close()
    return data

if __name__ == "__main__":
    main()
