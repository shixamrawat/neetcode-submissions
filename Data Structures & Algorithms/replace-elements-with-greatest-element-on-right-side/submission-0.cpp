class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>prefix(n);
        int maxi=-1;
        prefix[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            maxi=max(maxi,arr[i+1]);
            prefix[i]=maxi;
        }
        return prefix;
    }
};