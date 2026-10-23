class Solution {
public:
    void getNsl(vector<int>& arr,vector<int>& nsl) {
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nsl[i]=-1;
            }else{
                nsl[i]=st.top();
            }
            st.push(i);
        }
    } 

    void getNsr(vector<int>& arr,vector<int>& nsr) {
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nsr[i]=arr.size();
            }else{
                nsr[i]=st.top();
            }
            st.push(i);
        }
    }   
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nsl(n);
        vector<int>nsr(n);
        getNsl(arr,nsl);
        getNsr(arr,nsr);

        int m=1e9+7;
        long long sum=0;

        for(int i=0;i<n;i++){
            long long curr=1LL*arr[i]*(i-nsl[i])*(nsr[i]-i);
            sum=(sum+curr)%m;
        }
        return sum;
    }
};