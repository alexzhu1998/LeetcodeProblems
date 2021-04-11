import fileinput

with fileinput.input(files = ('input.txt')) as f: 
    input=[]
    for lines in f:
        input.append(lines)

# str1 = input()
numbers = [int(item) for item in input[0].split()]
# str2 = input()
target = int(input[1])
# # 1,3,7,11,13
# 1 2 3 4 5
# output = 4


print(numbers)
print(target)

# for each number 

def dp(arr,m,n):
# # dp[i+1]
# def dp(arr,m,n):
#     table = [[0 for x in range(m)] for x in range(n+1)]

#     for i in range(m):
#         table[0][i] = 1
#     for i in range(1,n+1):
#         for j in range(m):

#             x = table[i - arr[j]][j] if i - arr[j] >= 0 else 0

#             y = table[i][j-1] if j >= 1 else 0

#             table[i][j] = x + y
#     return table
# print(dp(numbers,len(numbers),30))

    

