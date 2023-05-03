//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int unboundedknapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[N+1][W+1];
        for(int i = 0;i<N+1;i++){
           for(int j = 0;j<W+1;j++){
               if(i == 0 || j==0){
                   dp[i][j] = 0;
               }
           }
       }
       for(int i = 1;i<N+1;i++){
           for(int j = 1;j<W+1;j++){
               if(wt[i-1] <= j){
                   dp[i][j]=max(dp[i-1][j], val[i-1] + dp[i][j - wt[i-1]]);
               }
               else{
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       
       return dp[N][W];
    }
    int cutRod(int price[], int n) {
        //code here
        int arr[n];
        for(int i = 0;i<n+1;i++){
            arr[i] = i+1;
        }
        
        int ans  = unboundedknapSack(n,n,price,arr);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends