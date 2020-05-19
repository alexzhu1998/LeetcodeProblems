import array 
import bisect
import collections 
# import sortedcontainers

class Solution:
    def findAnagrams(self, s: str, p: str):# -> List[int]:
        if s == "":
            return []
        l = []
        
        d = {}
        dp = {}
        for item in p:
            if item in dp:
                dp[item] += 1
            else:
                dp[item] = 1
        for item in s[0:len(p)]:
            if item in d:
                d[item] += 1
            else:
                d[item] = 1
        if d == dp:
            l.append(0)
        for i in range(1,len(s)-len(p)+1):
            strL = s[i-1:len(p)+i]
            
            if d[strL[0]] > 1:
                d[strL[0]] -= 1
            else:
                d.pop(strL[0],None)
            
                
            if strL[-1] in d:
                d[strL[-1]] += 1
            else:
                d[strL[-1]] = 1
            print(d)
            print(dp)
            if d == dp:
                l.append(i)
            
        return l


if __name__ == "__main__":
    with open("input.txt", "r") as f:
        s = f.readline().strip().strip("\"")
        p = f.readline().strip().strip("\"")
    sol = Solution()
    res = sol.findAnagrams(s,p)
    print(res)
