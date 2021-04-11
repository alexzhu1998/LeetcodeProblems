import sys

# From stdin, read strings and print to C++ input.txt

# [-1,0,3,5,9,12]
list_of_input = []
stack = []
for line in sys.stdin:
    line = line.strip()
    # recursively append stuff into stack
    chars = '\"[]'
    for c in chars:
        line = line.replace(c,'')
    list_of_input.append(line.split(","))

with open('cppInput.txt', 'a') as f:
    for item in list_of_input:
        for x in item: 
            f.write(str(x) + " ")
        f.write("\n")

    # print(l)

# example test cases
# ["TwoSum", "add", "add", "add", "find", "find"]
# [[], [1], [3], [5], [4], [7]]
# 


# Example Input
# ["StreamChecker","query","query","query","query","query","query","query","query","query","query","query","query"]
# [[["cd","f","kl"]],["a"],["b"],["c"],["d"],["e"],["f"],["g"],["h"],["i"],["j"],["k"],["l"]]

# Expected output
# length of the outer list
# StreamChecker
# query
# query
# query
# query
# query
# query
# query
# ...
# length of how many inputs
# cd f kl
# a 
# b
# c
# d
# e
# ...


# Example Input
# ["Solution", "pick", "pick", "pick"]
# [[[[1, 1, 5, 5]]], [], [], []]

# Example Output
# 4
# Solution
# pick
# pick
# pick
# 1 1 5 5
# 


# [[1,100],[11,22],[1,11],[2,12]]
# 4
# 1 100
# 11 22
# 1 11
# 2 12