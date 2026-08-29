class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>> a;

        for(int i=0;i<n;i++)
            a.push_back({nums[i],i});

        sort(a.begin(),a.end());

        int i=0;

        while(i<n){
            int j=i;

            while(j+1<n && a[j+1].first-a[j].first<=limit)
                j++;

            vector<int> pos;

            for(int k=i;k<=j;k++)
                pos.push_back(a[k].second);

            sort(pos.begin(),pos.end());

            for(int k=0;k<pos.size();k++)
                nums[pos[k]]=a[i+k].first;

            i=j+1;
        }

        return nums;
    }
};