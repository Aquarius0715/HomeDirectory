import csv

class Train:
    def __init__(self, passengerId, survived, pClass, name, sex, age, sibSp, parch, ticket, fare, cabin, embarked):
        self.passengerId = passengerId
        self.survived = survived
        self.pClass = pClass
        self.name = name
        self.sex = sex
        self.age = age
        self.sibSp = sibSp
        self.parch = parch
        self.ticket = ticket
        self.fare = fare
        self.cabin = cabin
        self.embarked = embarked

def main():
    male = 0
    female = 0
    for train in loadTrain():
        if train.sex == "male":
            male += 1
        elif train.sex == "female":
            female += 1

    print("male: " + str(male) + " female: " + str(female))

def loadTrain():
    data: [Train] = []
    with open('train.csv', 'r') as f:
        reader = csv.reader(f)
        for line in reader:
            data.append(Train(line[0], line[1], line[2], line[3], line[4], line[5], line[6], line[7], line[8], line[9], line[10], line[11]))
    data.pop(0)
    return data
    
if __name__ == "__main__":
    main()
