class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> arr1=arr;
        unordered_map<int,int> mp;
        sort(arr.begin(),arr.end());
        int rank=1;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])==mp.end())
            mp[arr[i]]=rank++;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr1[i]];
        }
        return arr;
    }
};