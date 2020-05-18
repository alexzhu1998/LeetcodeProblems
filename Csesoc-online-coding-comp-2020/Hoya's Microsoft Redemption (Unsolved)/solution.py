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

if __name__ == '__main__':
    n = int(input().strip())

    strings = []

    for _ in range(n):
        strings_item = input()
        strings.append(strings_item)

    maxlen = int(input().strip())

    hoyasMSRedemption(strings, maxlen)