#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'memelord' function below.
#
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER gribben_count
#  3. INTEGER_ARRAY follower_count
#

def memelord(n, gribben_count, follower_count):
    # Write your code here

if __name__ == '__main__':
    num = int(input().strip())

    gc = int(input().strip())

    fc = []

    for _ in range(num - 1):
        fc_item = int(input().strip())
        fc.append(fc_item)

    memelord(num, gc, fc)