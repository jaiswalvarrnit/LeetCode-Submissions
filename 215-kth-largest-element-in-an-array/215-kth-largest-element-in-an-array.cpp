class Solution {
public:
    typedef priority_queue<int, vector<int>, greater<int>> pqe;
    int findKthLargest(vector<int>& nums, int k) {
        pqe pq;
        for(auto x:nums)
        {
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};