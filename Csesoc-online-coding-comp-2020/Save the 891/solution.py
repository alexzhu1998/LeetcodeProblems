#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'save_the_891' function below.
#
# The function accepts following parameters:
#  1. INTEGER stopsTotal
#  2. INTEGER numStopsCompulsory
#  3. INTEGER_ARRAY stopsComp
#  4. INTEGER numConnections
#  5. 2D_INTEGER_ARRAY connections
#

def save_the_891(stopsTotal, numStopsCompulsory, stopsComp, numConnections, connections):
    # Write your code here

if __name__ == '__main__':
    st = int(input().strip())

    nsc = int(input().strip())

    sc = list(map(int, input().rstrip().split()))

    nc = int(input().strip())

    c = []

    for _ in range(nc):
        c.append(list(map(int, input().rstrip().split())))

    save_the_891(st, nsc, sc, nc, c)