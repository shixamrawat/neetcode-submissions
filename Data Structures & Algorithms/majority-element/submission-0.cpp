class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0];
        int count=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==ans){
                count++;
            }else{
                count--;
            }
            if(count<1){
                ans=nums[i];
                count=1;
            }
        }
        return ans;
    }
};