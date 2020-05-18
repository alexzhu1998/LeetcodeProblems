#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'challenge_exercise' function below.
#
# The function accepts following parameters:
#  1. 2D_INTEGER_ARRAY grid
#  2. INTEGER n
#

def challenge_exercise(grid, n):
    # Write your code here

if __name__ == '__main__':
    num = int(input().strip())

    g = []

    for _ in range(num):
        g.append(list(map(int, input().rstrip().split())))

    challenge_exercise(g, num)