class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        vector<int>ans;
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]==val)continue;
            ans.push_back(nums[j]);
        }
        for(int j=0;j<ans.size();j++){
            nums[j]=ans[j];
        }
        return ans.size();
    }
};