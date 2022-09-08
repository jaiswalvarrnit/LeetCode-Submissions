class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
         return a.second < b.second;
    }
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        unordered_map<int, int> m;
        for(int i = 0;i<n;i++){
            m[arr[i]] ++;
        }
        vector<pair<int, int> > A;
        for (auto& it : m) {
            A.push_back(it);
        }
        sort(A.rbegin(), A.rend(), cmp);
        int req = (n + 1)/ 2;
        int count = 0;
        for (auto& it : A) {
            count += it.second;
            ans ++;
            if(count >= req) break;
        }        
        return ans;
    }
};