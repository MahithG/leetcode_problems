class Solution:
    def captureForts(self, forts: List[int]) -> int:
        i=0
        j=0

        while j<len(forts) and forts[j]==0:
            i+=1
            j+=1
        k=0
        if i>=len(forts):
            return 0
            
        if forts[i]==1:
            k=-1
        else:
            k=1
        ans=0
        while j<len(forts):
            j+=1
            while j<len(forts) and forts[j]==0:
                j+=1
            
            if j>=len(forts):
                break
            if forts[j]==k:
                ans=max(ans,j-i-1)
            i=j
            if forts[i]==1:
                k=-1
            else:
                k=1
        return ans


            

            

        