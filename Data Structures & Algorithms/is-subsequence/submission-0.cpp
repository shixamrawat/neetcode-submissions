class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        if(n>m)return false;
        int j=0;
        for(int i=0;i<n;i++){
            while(j<m && s[i]!=t[j]) j++;
            if(j==m) return false;
            j++;
        }
        return true;
    }
};