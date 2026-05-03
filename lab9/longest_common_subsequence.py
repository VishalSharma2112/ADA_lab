def long_chain_sub(LCS, str1, str2):
    n1 = len(str1)
    n2 = len(str2)

    for i in range(n1):
        for j in range(n2):
            if str1[i] == str2[j]:
                LCS[i][j] = 1 + LCS[i-1][j-1]
            else:
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1])


str1 = "STONE"
str2 = "LONGEST"

LCS = [[0]* (len(str2)+1) for _ in range(len(str1)+1)]

long_chain_sub(LCS, str1, str2)

for row in range(len(LCS)-1):
    for j in range(1, len(LCS[row])-1):
        print(LCS[row][j], end="    ")
    print()