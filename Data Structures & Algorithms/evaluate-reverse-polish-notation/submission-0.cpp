class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string s:tokens){
            if(s=="+"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                st.push(first+second);
            }else if(s=="-"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                st.push(second-first);
            }else if(s=="*"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                st.push(second*first);
            }else if(s=="/"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                st.push(second/first);
            }else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};