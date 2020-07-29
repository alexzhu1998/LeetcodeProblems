import sys

string = input()
var = string.split()
if (var[0] == "") or (var[1] == ""):
    print("No valid input")
    exit
# str1 = [int(item) for item in var[0]]
sum1 = 0
for item in var[0]:
    sum1+=int(item)
sum2 = 0
for item in var[1]:
    sum2+=int(item)
# sum1 = [sum+int(item) for item in var[0]]

# for item in var[0]
print(sum1%sum2)
# print("hello")
