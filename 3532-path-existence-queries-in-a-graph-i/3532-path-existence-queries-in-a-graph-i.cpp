class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> cnt(n);
        int i=0;
        int cnt1=0;
        cnt[0]=0;
        for(int j=1;j<n;j++){
            if(nums[j]-nums[j-1]>maxDiff){
                cnt1++;
                i=j;
            }
            cnt[j]=cnt1;
        }
        vector<bool> ans;
        for(auto q:queries){
            ans.push_back(cnt[q[0]]==cnt[q[1]]);
        }
        return ans;
    }
};