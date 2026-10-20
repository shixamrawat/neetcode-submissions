class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int ans=0;
        for(string ch:operations){
            if(ch=="+"){
                int f=st.top();
                st.pop();
                int s=st.top();
                st.push(f);
                st.push(f+s);
                ans+=st.top();
            }else if(ch=="D"){
                int f=st.top();
                st.push(f*2);
                ans+=st.top();
            }else if(ch=="C"){
                int f=st.top();
                st.pop();
                ans-=f;
            }else{
                st.push(stoi(ch));
                ans+=st.top();
            }
        }
        return ans;
    }
};