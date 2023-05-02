//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int perfectSum(vector<int> arr, int n, int sum)
	{
        // Your code goes here
        // int n = arr.size();
        int dp[n+1][sum+1];
        for(int i = 0;i<n+1;i++){
            for(int j = 0;j<sum+1;j++){
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 1; 
            }
        }
        
        for(int i = 1;i<n+1;i++){
            for(int j = 0;j<sum+1;j++){
                if(arr[i-1] <= j){
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j - arr[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
	}
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        
        int n = A.size();
        
        
        int sum = 0;
        for(auto x : A) sum += x;
        
        if(sum-target < 0 || ((target+sum) % 2)) return 0;

        int reqdiff=(target+sum)/2;
	    return perfectSum(A,n,reqdiff);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends