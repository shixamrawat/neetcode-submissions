class Solution {
public:
    vector<int> getRow(int n) {
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
};
