#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'calculate_days' function below.
#
# The function accepts following parameters:
#  1. STRING start
#  2. STRING end
#

def calculate_days(start, end):
    # Write your code here
    # print(start)
    startday= int(start[0:2])
    startmonth = int(start[2:4])
    startyear = int(start[4:])
    endday= int(end[0:2])
    endmonth = int(end[2:4])
    endyear = int(end[4:])
    # if difyear != 0:
    # convert start to days 
    # convert end to days 

    def convertDays(year,month,day):
        totalDays = 0
        for i in range(1,year):
            if (i%2 == 1 ) or (i%10 == 0):
                totalDays += 669
            else:
                totalDays += 668
        for i in range(1,month):
            if (i%6 == 0):
                totalDays += 27
            else: 
                totalDays += 28
        totalDays += day
        return totalDays
    print(convertDays(endyear,endmonth,endday)-convertDays(startyear,startmonth,startday))

    return
    


    
    # print(end)

if __name__ == '__main__':
    with open("input.txt", "r") as f:
        s = f.readline().strip()

        e = f.readline().strip()

        calculate_days(s, e)    