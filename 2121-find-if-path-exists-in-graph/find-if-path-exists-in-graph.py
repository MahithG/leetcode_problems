class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        class Unionfind():
            def __init__(self,n):
                self.parent=[i for i in range(n)]
                self.rank=[0]*n
            def find(self,x):
                if x!=self.parent[x]:
                    self.parent[x]=self.find(self.parent[x])
                return self.parent[x]
            
            def union(self,i,j):
                pi=self.find(i)
                pj=self.find(j)
                if self.rank[pi]>self.rank[pj]:
                    self.parent[pj]=pi
                elif self.rank[pj]>self.rank[pi]:
                    self.parent[pi]=pj
                else:
                    self.parent[pj]=pi
                    self.rank[pi]+=1
                return 
        x=Unionfind(n)
        for edge in edges:
            if x.find(edge[0])!=x.find(edge[1]):
                x.union(edge[0],edge[1])
        if x.find(source)==x.find(destination):
            return True
        return False
                    
        