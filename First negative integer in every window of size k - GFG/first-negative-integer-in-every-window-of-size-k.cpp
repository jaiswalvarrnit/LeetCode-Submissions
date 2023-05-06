//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    
    vector<long long> ans;
    list<long long> negSt; // stores the neagtive nums in list
    
    int i = 0;
    int j = 0;
    
    while(j<N){
        if(A[j] < 0) negSt.push_back(A[j]); // if neg push in list
        if(j-i+1 < K) j++; // increment till reach window size
        else if(j-i+1 == K){
            if(negSt.size() == 0){
                ans.push_back(0); // if size 0 means no neagtive so push 0
            }
            else{
                ans.push_back(negSt.front()); // push front most element of list as it is the left most negative
            }
            if(A[i]<0){
                negSt.pop_front(); // now pop the number from list as we have moved from that number in our array
            }
            i++;
            j++;  // move the window
        }
    }
    
    return ans;
    
    
 }