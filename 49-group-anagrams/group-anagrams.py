class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        dic={

        }
        for s in strs:
            p=list(s)
            p.sort()
            p="".join(p)
            if p not in dic:
                dic[p]=[s]
            else:
                dic[p].append(s)
        ans=[]
        for x in dic:
            ans.append(dic[x])
        return ans
