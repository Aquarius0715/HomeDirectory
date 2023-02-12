String='dododd'
print (String)
StringLength = len(String)

j = 0
i = 1
PrefixSuffixArray = [0]

while len(PrefixSuffixArray) < StringLength:
    if String[j] == String[i]:
        PrefixSuffixArray.append(j+1)
        i += 1
        j += 1
    else:
        if j == 0:
            PrefixSuffixArray.append(0)
            i += 1
        if j != 0:
            j = PrefixSuffixArray[j-1]

print (PrefixSuffixArray)
