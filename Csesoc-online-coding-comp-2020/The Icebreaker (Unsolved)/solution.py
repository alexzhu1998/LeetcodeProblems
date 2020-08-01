#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'icebreaker' function below.
#
# The function accepts following parameters:
#  1. INTEGER xD
#  2. INTEGER yD
#  3. INTEGER zD
#

def icebreaker(xD, yD, zD):
    # print(xD)
    # print(yD)
    # print(zD)
    # Write your code here
    box1 = (5,4,3)
    box2 = (2,3,10)
    box3 = (9,4,3)
    # when two boxes were combined together, take max of the two dimension, add one dimension.
    




    return

if __name__ == '__main__':
    with open("input.txt", "r") as f:
        xDimension = int(f.readline().strip())

        yDimension = int(f.readline().strip())

        zDimension = int(f.readline().strip())

        icebreaker(xDimension, yDimension, zDimension)