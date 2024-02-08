//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution

{

    public:

    //Function to find minimum number of attempts needed in 

    //order to find the critical floor.

   int eggD(int n,int k, vector<vector<int>>&dp){

               // your code here

        if(n==1){

            return k; 

        }

        if(n==0){

            return 1; 

        }

        if(k==0){

            return 0; 

        }

        if(dp[n][k]!=-1){

            return dp[n][k]; 

        }

        int a=1e9;  

        for(int i=1;i<=k;i++){

             int l=max(eggD(n-1,i-1,dp)+1,eggD(n,k-i,dp)+1); 

          a=min(a,l); 

            

        }

        return dp[n][k]=a; 

   }

    int eggDrop(int n, int k) 

    {

   vector<vector<int>>dp(n+1, vector<int>(k+1,-1)); 

    return eggD(n,k,dp); 

    }

};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends