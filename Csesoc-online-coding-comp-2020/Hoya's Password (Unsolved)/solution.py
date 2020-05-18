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
    # Write your code here

if __name__ == '__main__':
    num = int(input().strip())

    strings = []

    for _ in range(num):
        strings_item = input()
        strings.append(strings_item)

    hoyas_Password(num, strings)