s = input()
s = s[::-1]
for i in range(len(s)) :
    if s[i] >= '0' and s[i] <= '9' :
        print(s[i], end = "")
    else :
        print("'" + str(ord(s[i])) + "'",  end = "")
