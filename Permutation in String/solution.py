class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if s2 == "":
            return False
        if s1 == "":
            return True
        ls1 = len(s1)
        ls2 = len(s2)
        ds1 = {}
        for item in s1:
            if item in ds1:
                ds1[item] += 1
            else:
                ds1[item] = 1
        
        ds2 = {}
        for item in s2[0:len(s1)]:
            if item in ds2:
                ds2[item] += 1
            else:
                ds2[item] = 1
        if ds2 == ds1:
            return True
        for i in range(1,ls2-ls1+1):
            if ds2[s2[i-1]] > 1:
                ds2[s2[i-1]] -= 1
            else:
                ds2.pop(s2[i-1],None)
                
            if s2[i+ls1-1] in ds2:
                ds2[s2[i+ls1-1]] += 1
            else:
                ds2[s2[i+ls1-1]] = 1
            # print(ds2)
            if ds1 == ds2:
                return True
        return False