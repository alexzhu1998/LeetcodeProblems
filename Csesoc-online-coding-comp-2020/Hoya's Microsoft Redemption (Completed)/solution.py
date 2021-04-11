#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'hoyasMSRedemption' function below.
#
# The function accepts following parameters:
#  1. STRING_ARRAY words
#  2. INTEGER maxlength
#

def hoyasMSRedemption(words, maxlength):
    # Write your code here
    # print(words)
    # print(maxlength)
    newline = []
    i=0
    while i < len(words):
        newline.append(words[i])
        line = ' '.join(newline)
        # print(line)
        # print(len(line))
        # break
        if len(line) >= maxlength:
            if (len(newline) != 1):
                newline.pop()
            else:
                i+=1
            print(' '.join(newline).strip())
            newline = []
        else:
            i+=1
    print(' '.join(newline).strip())
        # print (line)
        
    return
            

if __name__ == '__main__':
    with open("input.txt","r") as f:

        n = int(f.readline().strip())

        strings = []

        for _ in range(n):
            strings_item = f.readline().strip()
            strings.append(strings_item)

        maxlen = int(f.readline().strip())

        hoyasMSRedemption(strings, maxlen)