class Solution {
public:
    vector<int>helper(int n){
        vector<int>curr;
        curr.push_back(1);
        long long temp=1;
        for(int i=0;i<n;i++){
            temp*=(n-i);
            temp/=(i+1);
            curr.push_back(temp);
        }
        return curr;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>curr;
        for(int i=0;i<numRows;i++){
            curr=helper(i);
            ans.push_back(curr);
        }
        return ans;
    }
};