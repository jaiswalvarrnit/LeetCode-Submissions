class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> maxh;
        int n = points.size();
        for(int i = 0;i<n;i++){
            int dist = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            maxh.push({dist,{points[i][0],points[i][1]}}); 
                if(maxh.size() > k){
                    maxh.pop();
                }
        }
        vector<vector<int>> ans;
        while(maxh.size() > 0){
            ans.push_back({maxh.top().second.first,maxh.top().second.second});
            maxh.pop();
        }
        return ans;        
    }
};