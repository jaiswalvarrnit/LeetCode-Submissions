class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(auto x : operations){
            if(x == "--X" or x == "X--") ans -= 1;
            else ans += 1;
        }
        return ans;
    }
};