class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        import heapq
        from collections import     Counter
        freq=Counter(nums)
        heap=[]
        for x in freq:
            heapq.heappush(heap,(freq[x],x))
            if len(heap)>k:
                heapq.heappop(heap)
        ans=[]
        for x in heap:
            ans.append(x[1])
        return ans
        