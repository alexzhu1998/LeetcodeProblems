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
    if stopsTotal == 1:
        print('Yes')
        return
    graph = {}
    for item in connections:
        if item[0] in graph.keys():
            graph[item[0]].append(item[1])
        else:
            graph[item[0]] = [item[1]]
    print(graph)
    print(stopsTotal)
    print(numStopsCompulsory)
    stopsComp = set(stopsComp)
    print(stopsComp)
    print(numConnections)
    print(connections)
    q = []
    q.append(1)
    traversed = set()
    while q:
        cur = q.pop(0)
        for item in graph[cur]:
            if item not in traversed:
                if item in stopsComp:
                    stopsComp.remove(item)
                traversed.add(item)
                q.append(item)
        


    # bfs to find 

    return
if __name__ == '__main__':
    with open("input.txt","r") as f:
        st = int(f.readline().strip())

        nsc = int(f.readline().strip())

        sc = list(map(int, f.readline().rstrip().split()))

        nc = int(f.readline().strip())

        c = []

        for _ in range(nc):
            c.append(list(map(int, f.readline().rstrip().split())))

        save_the_891(st, nsc, sc, nc, c)