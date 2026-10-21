class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n=asteroids.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            int temp=asteroids[i];
            if(temp>0 || st.empty()){
                st.push(temp);
            }else{
                while(!st.empty() && st.top()>0 && st.top()<abs(temp)){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(temp)){
                    st.pop();
                }
                else if(st.empty() || st.top()<0 ){
                    st.push(temp);
                }
            }
        }
        vector<int>ans(st.size());
        int i=st.size()-1;
        while(!st.empty()){
            ans[i--]=st.top();
            st.pop();
        }
        return ans;
    }
};