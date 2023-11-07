//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int x, int y, int n, vector<vector<int>> visited,vector<vector<int>> &m){
        if((x >= 0 and x<n) and (y>=0 and y<n) and visited[x][y] == 0 and m[x][y] == 1) return true;
        else return false;
    }
    void solve(int x, int y, int n,  vector<string> &ans, vector<vector<int>> visited,vector<vector<int>> &m, string path){
        
        //base case
        if(x == n - 1 and y == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        //Down
        if(isSafe(x+1,y,n,visited,m)){
            path.push_back('D');
            solve(x+1,y,n,ans,visited,m,path);
            path.pop_back();
        }
        //Up
        if(isSafe(x-1,y,n,visited,m)){
            path.push_back('U');
            solve(x-1,y,n,ans,visited,m,path);
            path.pop_back();
        }
        //Right
        if(isSafe(x,y+1,n,visited,m)){
            path.push_back('R');
            solve(x,y+1,n,ans,visited,m,path);
            path.pop_back();
        }
        //Left
        if(isSafe(x,y-1,n,visited,m)){
            path.push_back('L');
            solve(x,y-1,n,ans,visited,m,path);
            path.pop_back();
        }
        
        visited[x][y] == 0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        int x =0;
        int y =0;
        vector<vector<int>> visited = m;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                visited[i][j] = 0;
            }
        }
        string path ="";
        vector<string> ans;
        if(m[0][0] == 0) return ans;
        solve(x,y,n,ans,visited,m,path);
        sort(ans.begin(),ans.end());
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends