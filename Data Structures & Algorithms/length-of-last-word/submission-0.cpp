class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int len=0,last=0;
        for(int i=0;i<n;i++){
            if(s[i]==' ') {
                len=0;
            }else{
                len++;
                last=len;
            } 
        }
        return last;
    }
};