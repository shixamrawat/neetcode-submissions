class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,float>>temp;
        for(int i=0;i<n;i++){
            float time = (float)(target - position[i]) / speed[i];
            temp.push_back({position[i],time});
        }
        sort(temp.begin(),temp.end(),[](const pair<int,float> &a,const pair<int,float> &b) {
            return a.first>b.first;
        });

        
        int fleet=0;
        for(int i=0;i<n;i++){
            auto curr=temp[i];
            while(i<n-1 && curr.second>=temp[i+1].second){
                i++;
            }
            fleet++;
        }
        return fleet;
    }
};