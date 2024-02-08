//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  
    long long int solver(int ind,int coins[],int N,int sum,vector<vector<long long int>> &dp){
        
        if(ind==0){
            if(sum%coins[ind]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(sum==0){
            return 1;
        }
        
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        
        long long int take=0;
        long long int nottake = 0;
        
        if(sum>=coins[ind]){
          take = solver(ind,coins,N,sum-coins[ind],dp);
        }
        
        nottake = solver(ind-1,coins,N,sum,dp);
        
        return dp[ind][sum] = take + nottake;
        
    }
  
    long long int count(int coins[], int N, int sum) {
        
        vector<vector<long long int>> dp(N,vector<long long int> (sum+1,-1));
        return solver(N-1,coins,N,sum,dp);
        // code here.
    }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends