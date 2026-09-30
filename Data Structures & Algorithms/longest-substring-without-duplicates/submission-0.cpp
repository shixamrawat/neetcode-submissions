class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,r=0;
        vector<int>hash(256,-1);
        int longest=0;
        while(r<n){
            if(hash[s[r]]!=-1 && hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
            hash[s[r]]=r;
            longest=max(longest,(r-l+1));
            r++;
        }
        return longest;
    }
};
