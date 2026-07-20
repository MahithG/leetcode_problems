class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        dic={

        }
        for s in strs:
            x=s
            p=list(s)
            p.sort()
            p="".join(p)
            if p not in dic:
                dic[p]=[x]
            else:
                dic[p].append(x)
        ans=[]
        for x in dic:
            ans.append(dic[x])
        return ans
