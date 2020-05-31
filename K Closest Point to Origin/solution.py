import array 
import bisect
import collections 
import heapq
# import sortedcontainers

class Solution:
    def kClosest(self, points, K: int):# -> List[int]:
        def dist(arr):
            return arr[0]**2 + arr[1]**2
        return heapq.nsmallest(K,points,dist)


if __name__ == "__main__":
    with open("input.txt", "r") as f:
        s = f.readline().strip().split("],[")
        s = [item.strip('[').strip(']') for item in s]
        s = [[int(item.split(",")[0]),int(item.split(",")[1])] for item in s]
        p = int(f.readline().strip())
    sol = Solution()
    res = sol.kClosest(s,p)
    print(res)
