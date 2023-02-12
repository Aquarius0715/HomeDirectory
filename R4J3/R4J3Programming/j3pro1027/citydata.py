MyFile =open('cityinfo.txt', 'r', encoding="utf-8")
data=MyFile.read()
DataRowSplitted = data.split('\n' )
num = len(DataRowSplitted)
i=0
while (i <num):
  CityName=DataRowSplitted[i].split(':')[0]
  Weather=DataRowSplitted[i].split(':')[1]
  Temperature=Weather.split(',')[0]
  Precipitation=Weather.split(',')[1]
  OutputString= "The temperature in Celsius of "+ CityName + " City is " + Temperature+  "°C and precipitation probability is " + Precipitation +"."
  print(OutputString)
  i=i+1
