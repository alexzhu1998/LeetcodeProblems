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
    follower_count.sort(reverse = True)
    rank = 0
    flag = 0
    for i in range(len(follower_count)-1):
        if follower_count[i] != follower_count[i-1]:
            rank += 1
        if gribben_count > follower_count[i]:
            flag = 1
            if rank < 4:
                print("tik tok memelord")
            else:
                print("six figure salary")
            break
    if flag == 0:
        if rank < 4:
            print("tik tok memelord")
        else:
            print("six figure salary")
    return
            
        

if __name__ == '__main__':
    num = int(input().strip())

    gc = int(input().strip())

    fc = []

    for _ in range(num - 1):
        fc_item = int(input().strip())
        fc.append(fc_item)

    memelord(num, gc, fc)