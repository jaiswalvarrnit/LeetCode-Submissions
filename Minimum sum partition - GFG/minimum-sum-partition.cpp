//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

  public:
	int minDifference(int arr[], int n)  {
        int sum = 0;
        sum = accumulate(arr, arr+n, sum);
        bool dp[n+1][sum+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i == 0) dp[i][j] = false; // first (row = false) coz we cant make a subsetsum if arr is empty
                if(j == 0) dp[i][j] = true; // first (col = true) coz we can take the null too
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j]; // we can take or cant take and `||` for taking if any possible
                }
                else{
                    dp[i][j] = dp[i-1][j]; // cant take coz it is greater than our sum
                }
            }
        }
        
        vector<int>v; // store valid subset or filtering or search space
        // Then we will store the all valid subset in our vector till half way coz we need positive value
        for(int i= 0;i<n+1;i++){
            for(int j = 0;j<(sum+1)/2;j++){
                if(dp[n][j] == true) v.push_back(j);
            }
        }
        for(int i=0;i<=sum/2;i++){
            if(dp[n][i] == true)
                v.push_back(i);
        }
        
        int mn = INT_MAX;
        // Now, calculaate the minimum value
        for(auto it : v){
            mn = min(mn, sum - (2 * it));
        }
        return mn; // This will be our min answer
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends