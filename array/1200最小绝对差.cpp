class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int mini=0x3f3f3f3f;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            int now=arr[i+1]-arr[i];
            if(now<mini){
                mini=now;
                ans.clear();
                ans.push_back({arr[i],arr[i+1]});
            }
            else if(now==mini){
                ans.push_back({arr[i],arr[i+1]});
            }

        }
        return ans;
    }
};