class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        // as nums of size less than 3 will always be valid no matter what
        if(n<=2) return n;

        // we start from the 2nd pointer as the first two element will always be correct
        int i=2;
        for(int j=2;j<n;j++){
            // we check if the curr j is not equal to the last 2 value of i 
            // that means we have either added prev unique twice if it was present more than once
            // or if it was present just once we added it once
            if(nums[j]!=nums[i-2]){
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};