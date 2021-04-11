#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'assignment' function below.
#
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER n
#  3. STRING_ARRAY dictionary
#

def assignment(s, n, dictionary):
    # Write your code here
    d = set(dictionary)
    res = []
    def backtrack(temp,pos):
        # print(pos)
        if pos == len(s):
            
            res.append(' '.join(temp))
            # print(temp)
            # print(res)
            return 
        for i in range(1,len(s)+1):
            # print(s[pos:i])
            if s[pos:i] in d:
                temp.append(s[pos:i])
                backtrack(temp,i)
                temp.pop()
        return
    backtrack([],0)
    # print(res)
    if res:
        for item in res:
            print(item)
    else:
        print(-1)
    


            


    return 
if __name__ == '__main__':
    # st = input()

    # nm = int(input().strip())

    # word_dictionary = input().rstrip().split()
    with open('input.txt', "r") as f:
        st = f.readline().strip()
        nm = int(f.readline().strip())
        word_dictionary = f.readline().rstrip().split()
        # print(word_dictionary)

        assignment(st, nm, word_dictionary)
