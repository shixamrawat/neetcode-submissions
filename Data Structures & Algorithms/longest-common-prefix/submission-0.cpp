class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        string ans="";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(strs[j][i]!=strs[0][i])return ans;
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};