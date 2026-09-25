class Solution {
public:
    string helper(string str){
        vector<int> mp(26,0);
        string key="";
        for(char ch:str){
            mp[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            key.append(mp[i],'a'+i);
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto& str: strs){
            string key=helper(str); 
            mp[key].push_back(str);
        }
        for(auto& m:mp){
            ans.push_back(m.second);
        }
        return ans;
    }
};
