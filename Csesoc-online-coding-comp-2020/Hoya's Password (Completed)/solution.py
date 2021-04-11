#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'hoyas_Password' function below.
#
# The function accepts following parameters:
#  1. INTEGER n
#  2. STRING_ARRAY words
#

def hoyas_Password(n, words):
    # 
    if n == 0:
        return
    m = len(words[0])
    res = [None]*m
    # print(res)
    # print(m)
    d = {}
    i = 0
    reverse = 0
    j = 0
    while j < m:
        # d[] = words[i][]
        res[j]=words[i][j]
        # print(i, end = ' ')
        # print(words[i][j], end = ' ')
        if i == n-1:
            reverse = 1
        if i == 0:
            reverse = 0
        if reverse:
            i-=1
        else:
            i+=1
        j+=1
    print(''.join(res))
    return
    

if __name__ == '__main__':
    # num = int(input().strip())

    # strings = []

    # for _ in range(num):
    #     strings_item = input()
    #     strings.append(strings_item)

    with open("input.txt", "r")  as f:
        num = int(f.readline().strip())
        strings = []
        for _ in range(int(num)):
            strings.append(f.readline().strip())
    # print(strings)

    hoyas_Password(num, strings)