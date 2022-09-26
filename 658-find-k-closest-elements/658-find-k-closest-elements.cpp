class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxh;//Max_heap
        for(int i=0;i<arr.size();++i)
        {
            maxh.push(make_pair(abs(x-arr[i]), arr[i]));
            if(maxh.size()>k)//for keeping only k elements in Heap
            {
                maxh.pop();
            }
        }
        vector<int> v;
        while(maxh.size()>0)
        {
            v.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(v.begin(), v.end());
        return v;
    }
};