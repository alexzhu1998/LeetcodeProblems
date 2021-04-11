#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'train_number' function below.
#
# The function accepts INTEGER n as parameter.
#

def train_number(n):
    # Write your code here
    l = [int(item) for item in str(n)]
    length = len(l)
    for i in range(1,length+1):
        # for each i, print all possible brackets of operations
        print(i)
    # for item in l:
    return



if __name__ == '__main__':
    with open("input.txt", "r") as f:
        num = int(f.readline().strip())

        train_number(num)